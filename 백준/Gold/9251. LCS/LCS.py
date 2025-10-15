arr1 = input()
arr2 = input()
dp = [[0] * 1001 for _ in range(1001)]

for i in range(1, len(arr1)+1):
    for j in range(1, len(arr2)+1):
        if arr1[i-1] == arr2[j-1]:
            dp[i][j] = 1 + dp[i-1][j-1]
        else:
            dp[i][j] = max(dp[i][j-1], dp [i-1][j])
            
print(dp[len(arr1)][len(arr2)])
    