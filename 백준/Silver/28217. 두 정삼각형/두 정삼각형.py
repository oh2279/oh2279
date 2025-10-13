def calc(A,B):
    cnt = 0
    for i in range(N):
        for j in range(len(A[i])):
            if A[i][j] != B[i][j]:
                cnt +=1
        
    return cnt

def flip(A):
    tmp = []
    for i in range(1,N+1):
        tmp.append([0 for _ in range(i)])
        
    for i in range(N):
        for j in range(i+1):
            tmp[i][j] = A[i][abs(j-i)]
            
    return tmp

def rotate(A):
    tmp = []
    for i in range(1,N+1):
        tmp.append([0 for _ in range(i)])
    # tmp = A 로 하면 안됨 (shallow copy)
    
    for i in range(N):
        for j in range(i,N): 
            tmp[j][i] = A[N-1-i][j-i]
    return tmp
    
N = int(input())
A = []
B = []
answer = float('INF')


for _ in range(N):
    A.append(list(map(int, input().split())))
for _ in range(N):
    B.append(list(map(int, input().split())))

flip_A = flip(A)

for _ in range(3):
    answer = min(answer, calc(A,B), calc(flip_A,B))
    A = rotate(A)
    flip_A = rotate(flip_A)
    
print(answer)

    