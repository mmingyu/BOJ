def ntob(n, b, l):
    ret = []
    while n:
        ret.append(str(n % b))
        n //= b
    while len(ret) < l:
        ret.append('0')
    return ''.join(ret[::-1])

def diff(x, y, b):
    ret = int(x, b) - int(y, b)
    return ntob(ret, b, len(x))

def solution(n, b):
    st = set([])
    while (True):
        y = ''.join(sorted(list(n)))
        x = y[::-1]
        if y in st:
            break
        st.add(y)
        n = diff(x, y, b)
    tar, ans = n, 0
    while True:
        ans += 1
        y = ''.join(sorted(list(n)))
        x = y[::-1]
        n = diff(x, y, b)
        if n == tar: break
    print(ans)
solution('1211', 10)
solution('210022', 3)
