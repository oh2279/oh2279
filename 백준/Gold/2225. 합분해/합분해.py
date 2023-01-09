import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline

n, k =map(int,input().split())
dp = [[0 for _ in range(k+1)] for _ in range(n+1)]

# n은 행, k는 열
for i in range(1,n+1):
    dp[i][1] = 1
    
for i in range(1,k+1):
    dp[1][i] = i
    
for i in range(2,n+1):
    for j in range(2,k+1):
        dp[i][j] = dp[i-1][j] + dp[i][j-1]
        
print(dp[n][k]%1000000000) 