N,M,R = map(int, input().split())
arr = [list(map(int, input().split())) for _ in range(N)]
task = list(map(int, input().split()))

def task1(arr):
    return arr[::-1]

def task2(arr):    
    return [row[::-1] for row in arr]

def task3(arr):
    return list(map(list, zip(*arr[::-1])))

def task4(arr):
    return list(map(list,zip(*arr)))[::-1]

def task5(arr):    
    H = len(arr)
    W = len(arr[0])
    tmp = [[0] * W for _ in range(H)]
    h = H // 2
    w = W // 2

    # sec2 = sec1
    for i in range(h):
        for j in range(w):
            tmp[i][j + w] = arr[i][j]

    # sec3 = sec2
    for i in range(h):
        for j in range(w, W):
            tmp[i + h][j] = arr[i][j]

    # sec4 = sec3
    for i in range(h, H):
        for j in range(w, W):
            tmp[i][j-w] = arr[i][j]

    # sec1 = sec4
    for i in range(h, H):
        for j in range(w):
            tmp[i - h][j] = arr[i][j]
    return tmp

def task6(arr):
    H = len(arr)
    W = len(arr[0])
    
    tmp = [[0] * W for _ in range(H)]
    
    h = H // 2
    w = W // 2
    
    # sec4 = sec1
    for i in range(h):
        for j in range(w):
            tmp[i+h][j] = arr[i][j]
            
    # sec3 = sec4
    for i in range(h,H):
        for j in range(w):
            tmp[i][j+w] = arr[i][j]
            
    # sec2 = sec3
    for i in range(h,H):
        for j in range(w,W):
            tmp[i-h][j] = arr[i][j]
            
    # sec1 = sec2
    for i in range(h):
        for j in range(w,W):
            tmp[i][j-w] = arr[i][j]
    
    return tmp

for t in task:
    if t==1: arr = task1(arr)
    elif t==2: arr = task2(arr)
    elif t==3: arr = task3(arr)
    elif t==4: arr = task4(arr)
    elif t==5: arr = task5(arr)
    elif t==6: arr = task6(arr)
    
for a in arr:
    print(*a) 