n,m = map(int,input().split())
maps = [list(map(int,input().split())) for _ in range(n)]
#print(maps)

dx = [0,1,0,-1]
dy = [1,0,-1,0]

from collections import deque

start = []
for i in range(n):
    for j in range(m):
        if maps[i][j] != 0:
            start.append([i,j,0])
temp = 0
ans = []
for s in start:
    dq = deque()
    dq.append(s)
    #print(s)
    visited = [[False] * m for _ in range(n)]
    visited[s[0]][s[1]]=True
    tmp = 0
    end = 0
    while dq:
        x,y,cost = dq.popleft()
        
        if cost >= tmp:
            end = maps[x][y]
            tmp = cost
        
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if nx >= 0 and nx <n and ny >=0 and ny<m and not visited[nx][ny] and maps[nx][ny] !=0:
                dq.append([nx,ny,cost+1])
                visited[nx][ny]=True
    if tmp >= temp and tmp !=0:
        ans.append([maps[s[0]][s[1]]+end, tmp])
        temp = tmp
#print(ans)
print(max(ans, key=lambda x : (x[1],x[0]))[0])