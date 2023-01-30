import sys
#sys.setrecursionlimit(10**6)
input = sys.stdin.readline

n = int(input())

wine = [0] + [int(input()) for _ in range(n)]
dp = [0 for _ in range(10001)] # i번쨰 와인까지 마셨을 때 마실 수 있는 최대치

dp[1] = wine[1]

if n>=2 :
  dp[2] = wine[1] + wine[2]
  if n>=3 :
    dp[3] = max(wine[1] + wine[3], wine[2] + wine[3], wine[1] + wine[2])
    if n>=4:
      for i in range(4,n+1):
        dp[i] = max(wine[i] + wine[i-1] + dp[i-3], dp[i-2]+wine[i], dp[i-1])
    
print(dp[n])