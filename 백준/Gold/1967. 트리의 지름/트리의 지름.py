import sys
from collections import deque
sys.setrecursionlimit(10**6)
input = sys.stdin.readline

def dfs(now,parent):
  for next, weight in tree[now]:
    if dist[next]==0 and next != parent:
      dist[next] = dist[now]+weight
      dfs(next,now)
      
if __name__ == "__main__":
  n = int(input())
  tree = [[] for _ in range(10001)]
  dist = [0 for _ in range(10001)]
  depth = 0
  
  for _ in range(n-1):
    s,e,c = map(int,input().split())
    tree[s].append([e,c])
    tree[e].append([s,c])
  
  dfs(1,0)
  point1 = max(range(1,n+1), key = lambda i : dist[i]) # 지름이 될 수 있는 한 점
  
  dist = [0 for _ in range(10001)]
  
  point2 = dfs(point1,0) # 지름을 완성하는 두번째 점

  print(max(dist))
