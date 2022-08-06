n, m = map(int, input().split())

for i in range(1, m + 1):
    print(0, i)

for i in range(m, n - 1):
    print(i, i + 1)