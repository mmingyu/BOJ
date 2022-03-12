def remove_num(mods, l, tar, cnt):
    flag = 0
    ret = ''
    for i in range(len(mods) - 1, -1, -1):
        if flag < cnt and mods[i] == tar:
            flag += 1
            continue
        ret += str(l[i])
    ret = ret[::-1]
    if len(ret) == 0: return 0
    return int(ret)

def only3(l):
    ret = ''
    for x in l:
        if x % 3 == 0: ret += str(x)
    return int(ret)

def solution(l):
    l = sorted(l)[::-1]
    mods = [l[i] % 3 for i in range(len(l))]
    total = sum(mods) % 3
    cnt = [0] * 3
    
    for mod in mods:
        cnt[mod] += 1
    
    if total == 1:
        if cnt[1] > 0:
            return remove_num(mods, l, 1, 1)
        if cnt[2] > 1:
            return remove_num(mods, l, 2, 2)
        elif cnt[0] > 0: return only3(l)
    elif total == 2:
        ret = 0
        if cnt[2] > 0:
            return remove_num(mods, l, 2, 1)
        if cnt[1] > 1:
            ret = remove_num(mods, l, 1, 2), 
        if cnt[0] > 0:
            ret = max(ret, only3(l))
            return ret
    else:
        return int(''.join(map(str, l)))
    return 0


print(solution([3, 1, 4, 1]))
print(solution([3, 1, 4, 1, 5, 9]))
print(solution([9, 8, 1, 0]))
print(solution([9, 0]))

