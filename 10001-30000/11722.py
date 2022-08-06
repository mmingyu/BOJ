n = int(input())
arr = list(map(int, input().split()))[::-1]

dp = [1 for i in range(1003)]

for i in range(n):
    for j in range(i):
        if arr[i] > arr[j]:
            dp[i] = max(dp[i], dp[j] + 1)

print(max(dp))
