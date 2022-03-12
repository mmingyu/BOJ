def solution(x, y):
    x, y = int(x), int(y)
    if x > y: x, y = y, x

    ans = 0
    while x > 1:
        if x < 1 or y < 1: break
        ans += (y // x)
        y -= x * (y // x)
        y, x = x, y % x
    if x < 1: return 'impossible'
    return str(ans + y - x)
    
print(solution('4', '7'))
print(solution('2', '1'))
print(solution('2', '4'))
