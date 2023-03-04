import sys
from collections import deque
#sys.setrecursionlimit(10**6)
input = sys.stdin.readline

def bfs():
  q = deque()
  level = 1

  for i in range(1,v+1):
    if visited[i]==0:
      q.append(i)
      visited[i] = level
      
      while q:
        now = q.popleft()
        
        for next in graph[now]:
          if visited[next]==0:
            q.append(next)
            visited[next] = -1 * visited[now]
          elif visited[next]==visited[now]: #
            return False
          
  return True

if __name__ == "__main__":
  t = int(input())
  for _ in range(t):
    v,e = map(int,input().split())
    graph = [[] for _ in range(v+1)]
    visited = [0] * (v+1)
    
    for _ in range(e):
      x,y = map(int,input().split())
      graph[x].append(y)
      graph[y].append(x)
      
    print('YES' if bfs() else 'NO')   