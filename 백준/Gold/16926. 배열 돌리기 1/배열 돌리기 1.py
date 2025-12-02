from collections import deque
import copy

N,M,R = map(int, input().split()) # 행, 열, 회전

arr = [list(map(int, input().split())) for _ in range(N)]


# 아래, 오른쪽, 위쪽, 왼쪽 순서
dx = [1,0,-1,0] 
dy = [0,1,0,-1]

depth = min(N,M) // 2
    

visited = [[False] * M for _ in range(N)]
tmp = copy.deepcopy(arr)

#print(depth)
for i in range(depth):
    coords = []       # 좌표 저장
    x, y = i, i       # 시작점 (i, i)
    d = 0             # 방향 인덱스
    coords.append((x, y))
    while True:
        nx = x + dx[d]
        ny = y + dy[d]
        # 현재 방향으로 계속 전진 가능할 때 
        if i <= nx < N - i and i <= ny < M - i:
            if (nx,ny) == (i,i): break
            coords.append((nx, ny)) # 좌표 저장
            x, y = nx, ny
        else:
            # 범위 밖이면 방향 전환
            d = (d + 1) % 4
        
    L = len(coords)           # 이 레이어 둘레 길이
    k = R % L                 # 실제로 의미 있는 회전 횟수
    
    if k == 0:
        # 그대로 복사
        for idx, (x, y) in enumerate(coords):
            tmp[x][y] = arr[x][y]
    else:
        # 원래 값들을 일렬로 뽑아서
        ring = [arr[x][y] for (x, y) in coords]
        # 반시계 방향으로 k칸 회전 (왼쪽으로 밀기)
        k = L- k
        rotated = ring[k:] + ring[:k]

        # 회전된 값을 tmp에 다시 채워 넣기
        for (x, y), val in zip(coords, rotated):
            tmp[x][y] = val
           
for i in range(N):
    print(*tmp[i])
