from collections import deque
n, k = map(int, input().split())

dq = deque()

for i in range(n):
    dq.append(i + 1)

ans = []
while dq:
    for i in range(k):
        if (i == k - 1):
            f = dq.popleft()
            ans.append(str(f))
        else:
            f = dq.popleft()
            dq.append(f)

print('<' + ', '.join(ans) + '>')