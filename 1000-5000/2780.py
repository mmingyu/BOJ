import sys
input = sys.stdin.readline

N = 1003
MOD = 1234567
arr = [
    [1, 2, 3],
    [4, 5, 6], 
    [7, 8, 9],
    [0]
]

dir = [[1, 0], [-1, 0], [0, 1], [0, -1]]
dp = [[0 if j != 1 else 1 for i in range(10)] for j in range(N)]

for i in range(N):
    for j in range(10):
        if j != 0: r, c = divmod(j - 1, 3)
        else: r, c = 3, 0
        for k in range(4):
            nr, nc = r + dir[k][0], c + dir[k][1]
            if nr < 0 or nc < 0 or nr > 3 or nc >= 3 or (nr == 3 and nc != 0): continue
            cur = (nr * 3 + nc + 1) % 10
            dp[i][j] += dp[i-1][cur]
            dp[i][j] %= MOD
            

t = int(input())
for _ in range(t):
    n = int(input())
    print(sum(dp[n]) % MOD)
