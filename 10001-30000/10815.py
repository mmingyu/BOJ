n = int(input())
st = set(map(int, input().split()))

n = int(input())
arr = list(map(int, input().split()))
for x in arr: 
    print('1' if x in st else '0', end=' ')