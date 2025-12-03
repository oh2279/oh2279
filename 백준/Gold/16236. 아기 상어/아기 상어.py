from collections import deque
N = int(input())
arr = [list(map(int, input().split())) for _ in range(N)]

def init():
    visited = [[0]*N for _ in range(N)]
    return visited

for i in range(len(arr)):
    for j in range(len(arr[i])):
       if arr[i][j] == 9: 
           start = (i,j)
           arr[i][j]=0

# 상, 좌, 우, 하
dx = [-1,0,0,1]
dy = [0,-1,1,0]

def mother(arr,size):
    for i in range(len(arr)):
        for j in range(len(arr[i])):
            if arr[i][j] !=0 and arr[i][j] < size: # 사이즈보다 작은게 하나라도 있다면 
                return False
    return True

def bfs(dq,visited):
    while dq:
        now, d,size = dq.popleft()
        for i in range(4):
            nx = now[0]+dx[i]
            ny = now[1]+dy[i]
            
            if nx >=0 and nx < N and ny >=0 and ny < N and visited[nx][ny]==0:
                if arr[nx][ny] <= size:
                    dq.append([[nx,ny],d+1,size])
                    visited[nx][ny] = 1
                    if arr[nx][ny] < size and arr[nx][ny] > 0:
                        distance[nx][ny]=d+1
                     
    return distance

time = 0
size = 2
eat = 0
cnt=0
while True:
    dq = deque()
    dq.append([start,0,size]) # start, distance, size
    visited = init()
    distance = init()
    visited[start[0]][start[1]] = 1
    distance = bfs(dq,visited)

    min_d = 1e+9
    for i in range(N):
        for j in range(N):
            # 먹는 기준이 좌상단이니까 만약 거리가 전부 같다면 처음 만나는 곳으로 이동
            # 거리가 다르면 가까운 곳으로 이동
            if distance[i][j] !=0 and min_d > distance[i][j]: 
                min_d = distance[i][j]
                target = (i,j)
    
    if min_d == 1e+9:
        break  
    
    arr[target[0]][target[1]]=0 
    time += min_d
    start = target
    eat += 1
    if eat == size:
        eat = 0
        size +=1

    #rint(arr,distance)
    if mother(arr,size):
        break
    
print(time)
            
