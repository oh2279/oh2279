import sys
from collections import deque
#sys.setrecursionlimit(10**6)
input = sys.stdin.readline

def manne_bfs():
  while mlist:
    x,y,dist = mlist.popleft()
    if dist == k :
      continue
    
    for i in range(4):
      nx = x + dx[i]
      ny = y + dy[i]    
      
      if nx >= n or nx < 0 or ny < 0 or ny >= m:
        continue
      if danger[nx][ny]:
        continue
      
      danger[nx][ny] = True
      mlist.append((nx,ny,dist+1))

def bfs(sx,sy,hp): 
  q = deque()
  q.append((sx,sy,hp))
  visited[sx][sy] = True
  
  while q:
    x,y,hp = q.popleft()
    
    if board[x][y] == 2:
      return hp 
  
    for i in range(4):
      nx = x + dx[i]
      ny = y + dy[i]
      
      if nx >= n or nx < 0 or ny < 0 or ny >= m:
        continue
      if board[nx][ny] == 1 or visited[nx][ny] or danger[nx][ny]:
        continue
      
      visited[nx][ny] = True
      q.append((nx,ny,hp+1))
  return -1

if __name__ == "__main__":
  n,m,k = map(int,input().split())
  
  board = []
  danger = [[False for _ in range(m)] for _ in range(n)]
  visited = [[False for _ in range(m)] for _ in range(n)]
  sx,sy=0,0
  mlist = deque()
  dx = [1,0,-1,0]
  dy = [0,1,0,-1]
  
  for i in range(n):
    info = list(map(int,input().split()))
    board.append(info)
    for j in range(len(info)):
      if info[j] == 4:
        sx = i
        sy = j
      elif info[j] == 3:
        mlist.append([i,j,0])
        board[i][j] = 1
        danger[i][j] = True
  #print(board)
  if k!= 0:
    manne_bfs()

  print(bfs(sx,sy,0))