from copy import deepcopy
import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline

n = int(input())
board = [list(map(int, input().split())) for _ in range(n)]

def move(map,dx):
  arr=[]
  if dx == 0: # up
    for j in range(n):
      top = 0
      for i in range(1,n):
        if map[i][j]:
          now = map[i][j]
          map[i][j] = 0
          if map[top][j]==now: # 내 바로 앞과 내가 같으면
            map[top][j] = now * 2
            top += 1
          elif map[top][j] == 0: # 나보다 앞에 있는 곳이 빈칸인 경우
            map[top][j] = now # 앞으로 땡겨줌
          else: # 나와 내 바로 앞이 다른 경우
            top +=1 # 포인터 하나 증가 시키고
            map[top][j] =now # 원래 자리에 원래 값 채워주기
                  
  elif dx == 1: # down
    for j in range(n):
      top = n-1
      for i in range(n-2,-1,-1):
        if map[i][j]:
          now = map[i][j]
          map[i][j] = 0
          if map[top][j]==now: # 내 바로 앞과 내가 같으면
            map[top][j] = now * 2
            top -= 1
          elif map[top][j] == 0: # 나보다 앞에 있는 곳이 빈칸인 경우
            map[top][j] = now # 앞으로 땡겨줌
          else: # 나와 내 바로 앞이 다른 경우
            top -=1 # 포인터 하나 증가 시키고
            map[top][j] =now # 원래 자리에 원래 값 채워주기
          
  elif dx == 2: # left
    for i in range(n):
      top = 0
      for j in range(1,n):
        if map[i][j]:
          now = map[i][j]
          map[i][j] = 0
          if map[i][top]==now: # 내 바로 앞과 내가 같으면
            map[i][top] = now * 2
            top += 1
          elif map[i][top] == 0: # 나보다 앞에 있는 곳이 빈칸인 경우
            map[i][top] = now # 앞으로 땡겨줌
          else: # 나와 내 바로 앞이 다른 경우
            top +=1 # 포인터 하나 증가 시키고
            map[i][top] =now # 원래 자리에 원래 값 채워주기
          
  elif dx == 3: # right
    for i in range(n):
      top = n-1
      for j in range(n-2,-1,-1):
        if map[i][j]:
          now = map[i][j]
          map[i][j] = 0
          if map[i][top]==now: # 내 바로 앞과 내가 같으면
            map[i][top] = now * 2
            top -= 1
          elif map[i][top] == 0: # 나보다 앞에 있는 곳이 빈칸인 경우
            map[i][top] = now # 앞으로 땡겨줌
          else: # 나와 내 바로 앞이 다른 경우
            top -=1 # 포인터 하나 증가 시키고
            map[i][top] =now # 원래 자리에 원래 값 채워주기
      
  return map

def dfs(graph, cnt):
    global ans
    if cnt == 5:
      for i in range(n):
        ans = max(ans, max(graph[i]))
      return
    
    for k in range(4):
      tmp_board = move(deepcopy(graph),k) 
      dfs(tmp_board,cnt+1)
      
ans = 0
dfs(board,0)
print(ans)