s = input()

st = set()
for i in range(len(s)):
    for j in range(1, len(s) + 1):
        if i + j <= len(s):
            st.add(s[i : i+j])
print(len(st))