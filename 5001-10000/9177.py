import sys
input = sys.stdin.readline

def dpf(x, y):
    if dp[x][y] != -1: return dp[x][y]
    if x + y == len(c): return 1
    if x < len(a) and c[x + y] == a[x]: dp[x][y] = dpf(x + 1, y)
    if y < len(b) and c[x + y] == b[y]: dp[x][y] = max(dp[x][y], dpf(x, y + 1))
    if dp[x][y] == -1: dp[x][y] = 0
    return dp[x][y]

tc = int(input())
for t in range(tc):
    a, b, c = input().split()
    dp = [[-1 for i in range(202)] for j in range(202)]
    print(f'Data set {t + 1}: ', end='')
    if dpf(0, 0) == 1: print('yes')
    else: print('no')
