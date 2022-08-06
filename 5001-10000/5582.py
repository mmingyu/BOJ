a = '@' + input()
b = '@' + input()
dp = [[0 for i in range(4004)] for j in range(4004)]
ans = 0

for i in range(1, len(a)):
    for j in range(1, len(b)):
        if a[i] == b[j]: dp[i][j] = dp[i-1][j-1] + 1
        ans = max(ans, dp[i][j])

print(ans)
