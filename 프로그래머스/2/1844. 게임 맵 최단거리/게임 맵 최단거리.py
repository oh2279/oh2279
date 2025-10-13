from collections import deque

def solution(maps):
    answer = -1
    n = len(maps)
    m = len(maps[0])
    
    dx = [1,0,-1,0]
    dy = [0,1,0,-1]
    visited = [[False] * m for _ in range(n)]
    
    dq = deque()
    visited[0][0] = True
    dq.append((0,0,1))
    
    while dq:
        x,y,cnt = dq.popleft()
        
        if x == n-1 and y == m-1:
            answer = cnt
            break
        
        for k in range(4):
            nx = x + dx[k]
            ny = y + dy[k]
            if 0<= nx < n and 0<= ny < m:
                if maps[nx][ny] == 1 and not visited[nx][ny]:
                    dq.append((nx,ny,cnt+1))
                    visited[nx][ny] = True
                                

    return answer