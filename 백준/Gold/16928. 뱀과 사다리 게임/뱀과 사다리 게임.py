import sys
from collections import deque
#sys.setrecursionlimit(10**6)
input = sys.stdin.readline

board = [0] + [ [i,0] for i in range(1,101)]
num = 1
ladder = []
visited = [False for _ in range(101)]

dx = [1,2,3,4,5,6]

def bfs():
  q = deque()
  q.append([1,0])
  visited[1] = True
  cnt = 0
  
  while q:
    x = q.popleft()
    cnt = x[1]
    
    if x[0] == 100:
      return cnt

    for i in range(len(dx)):
      nx = x[0] + dx[i]
      
      if nx > 100: continue
      jump = int(board[nx][1])
 
      if jump != 0 and not visited[jump]:
        q.append([jump,cnt+1])
        visited[jump]= True

      elif jump == 0 and not visited[nx]:
        q.append([nx,cnt+1])
        visited[nx]= True

n,m = map(int,input().split())

for i in range(n+m):
  x,y = map(int,input().split())
  ladder.append([x,y])
  
for i in range(1,101):
    for j in range(n+m):
      if ladder[j][0] == board[i][0]:
        board[i] = [num,ladder[j][1]]
        
print(bfs())