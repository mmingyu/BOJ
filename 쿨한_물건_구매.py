def solve(d, p, q):
    if d % p == 0 or d % q == 0:
        return d
    if q > p :
        p, q = q, p
    ans = p * (d // p + 1)
    for i in range(d // p, -1, -1):
        div, mod = divmod(d - (i * p), q)
        if mod == 0: 
            return d
        cal = i * p + (div + 1) * q
        if ans == cal: break
        ans = min(ans, cal)
    return ans

d, p, q = map(int, input().split())
print(solve(d, p, q))
