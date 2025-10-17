from itertools import permutations
n,k = map(int,input().split())
arr =[[0,0]]
for _ in range(n):
    x,y = map(int,input().split())
    arr.append([x,y])

dp = [[0]*(k+1) for _ in range(n+1)]

for i in range(1, n+1):
    #print(arr[i])
    w, v = arr[i]
    for k in range(1, k+1):
        if k >= w:
            dp[i][k] = max(dp[i][k-1], dp[i-1][k], v+ dp[i-1][k-w])
        else:
            dp[i][k] = max(dp[i][k-1], dp[i-1][k])
print(max(map(max, dp)))