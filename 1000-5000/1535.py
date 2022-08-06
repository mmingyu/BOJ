import sys
input = sys.stdin.readline

def solve(cur, last, x):
    global ans
    if last <= 0: return
    ans = max(x, ans)
    if cur == n: return
    solve(cur + 1, last - l[cur], x + j[cur])
    solve(cur + 1, last, x)

n = int(input())
l = list(map(int, input().split()))
j = list(map(int, input().split()))
ans = 0

solve(0, 100, 0)
print(ans)

