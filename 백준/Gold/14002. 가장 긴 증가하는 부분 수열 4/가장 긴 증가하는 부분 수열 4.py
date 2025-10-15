n = int(input())
arr = list(map(int,input().split()))
dp = [1] * n

for i in range(len(arr)):
    for j in range(i):
        if arr[i] > arr[j]:
            dp[i] = max(dp[i],dp[j]+1)
a = max(dp)
print(a)

res = []
for i in range(n-1,-1,-1):
    if dp[i] == a:
        res.append(arr[i])
        a -= 1

print(*sorted(res))