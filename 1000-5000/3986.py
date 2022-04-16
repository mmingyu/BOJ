n = int(input())
ans = 0

for i in range(n):
    s = input()
    st = []
    for c in s:
        if (len(st) == 0 or c != st[-1]): 
            st.append(c)
        else:
            st.pop()
    if (len(st) == 0): ans += 1
print(ans)    