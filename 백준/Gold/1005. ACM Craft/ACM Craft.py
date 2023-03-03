import sys
from collections import deque
#sys.setrecursionlimit(10**6)
input = sys.stdin.readline

def topology_sort():
  ans = [0] * (n+1)
  dq = deque()
  
  # 진입차수가 0인것부터 시작
  for i in range(1,n+1):
    if indegree[i] == 0:
      dq.append(i)
      ans[i] = time[i]
  
  while dq:
    start = dq.popleft()

    for next in construction[start]:
      ans[next] = max(time[next] + ans[start],ans[next])
      indegree[next] -= 1
      if indegree[next] ==0:
        dq.append(next)
        
  return ans[w]

if __name__ == "__main__":
  t = int(input())
  for _ in range(t):
    n,k = map(int,input().split())
    
    construction = [[] for _ in range(n+1)]
    indegree = [0] * (n+1)
    
    time = [0] + list(map(int,input().split()))
    for _ in range(k):
      x, y = map(int,input().split())
      construction[x].append(y)
      indegree[y] += 1
    w = int(input())
    
    print(topology_sort()) 