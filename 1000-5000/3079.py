import sys

n, m = map(int, sys.stdin.readline().split())
arr = []
for i in range(n):
    arr.append(int(sys.stdin.readline()))

def cnt(k):
    global n, arr
    ret = 0
    for i in range(n): ret += k // arr[i]
    return ret

l, r = 0, int(2e18)

while l + 1 < r:
    mid = (l + r) >> 1
    if cnt(mid) >= m: r = mid
    else: l = mid

print(r)
