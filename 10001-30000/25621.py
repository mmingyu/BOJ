import sys
input = sys.stdin.readline
MOD = int(1e9 + 7)

n, k = map(int, input().split())

def cal(of, k, num, op):
    if op == '+':
        return (of + (k + num) // MOD, (k + num) % MOD)
    if op == '-':
        if k - num < 0 and of > 0:
            return (of - 1, k + MOD - num)
        if k - num < 0 and of == 0:
            return (0, 0)
        return (of, k - num)
    if op == '*' and num == 0:
        return (0, 0)
    return (of + (k * num) // MOD, (k * num) % MOD)

k = (0, k)

for i in range(n):
    a, b = input().split()
    op1, num1 = a[0], int(a[1:])
    op2, num2 = b[0], int(b[1:])
    
    ofx, x = cal(k[0], k[1], num1, op1)
    ofy, y = cal(k[0], k[1], num2, op2)

    if ofx > ofy:
        k = (ofx, x)
    elif ofx < ofy:
        k = (ofy, y)
    else:
        if x > y: k = (ofx, x)
        else: k = (ofy, y)

print(k[1] % MOD)
