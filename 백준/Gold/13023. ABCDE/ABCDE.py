import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline

n, m = map(int,input().split())
ans = False

friend = [[] for _ in range(n)]
visited=[False for _ in range(n)]

for _ in range(m):
  a ,b = map(int,input().split())
  friend[a].append(b)
  friend[b].append(a)
  
def dfs(now,depth):
  global ans
  if depth == 4:
    ans=True
    return
  
  for x in friend[now]:
    if not visited[x]:
      visited[x] = True
      dfs(x,depth + 1)
      visited[x] = False
    
for i in range(n):
    visited[i] = True
    dfs(i,0)
    visited[i] = False
    if ans:
        break

if ans: print(1)
else: print(0)