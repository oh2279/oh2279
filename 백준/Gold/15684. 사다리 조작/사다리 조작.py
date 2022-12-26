import sys
input = sys.stdin.readline

def check():
    # i번 라인에서 출발
    for i in range(n):
        temp = i    
        for j in range(h):
            if graph[j][temp]: #만약 가로선이 있다면
                temp += 1
            elif temp > 0 and graph[j][temp - 1]: # 맨 왼쪽 라인이 아니면서 왼쪽 라인을 잇는 가로줄이 있다면
                temp -= 1
        if temp != i:
            return False
    return True

def dfs(cnt, x, y):
    global ans
    
    if check(): 
        ans = min(ans, cnt)
        return
    
    if cnt == 3: return
    
    if y>=n-1:
        x+=1
        y=0
    
    for i in range(x,h):
        if i==x: y=0
        for j in range(y,n-1):
            if graph[i][j] == 0 and cnt+1 < ans and graph[i][j+1]!=1 :# 가로줄이 없고 더 만들 수 있을 때
                if j>0 and graph[i][j-1] ==1:
                    continue
                graph[i][j]=1
                dfs(cnt+1,i,j+2)
                graph[i][j]=0
                    
n,m,h = map(int, input().split())
graph = [[0] * n for _ in range(h)]

for _ in range(m):
    a, b = map(int, input().split())
    graph[a - 1][b - 1] = 1
    
ans = 4

if m==0:
    print(0)
else:
    dfs(0,0,0)
    print(ans if ans <= 3 else -1)