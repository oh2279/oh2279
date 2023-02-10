import sys
from collections import deque
sys.setrecursionlimit(10**6)
input = sys.stdin.readline

def main():  
  print(bfs(1))
  
def bfs(start):
  cnt =0
  dq = deque()
  visited[start]=True
  for i in graph[start]:
    dq.append(i)
    
  while dq:
    node = dq.popleft()
    
    if not visited[node]:
      cnt+=1
      visited[node]=True
      for i in graph[node]:
        if not visited[i]:
          dq.append(i)
    
  return cnt
    
if __name__ == "__main__":
  node = int(input())
  edge = int(input())
  
  graph = [[] for _ in range(node+1)]
  visited = [False for _ in range(node+1)]

  for _ in range(edge):
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)
  
  main()