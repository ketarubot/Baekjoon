n = int(input())
arr = list(map(int, input().split()))
set_arr = set(arr)
result = list(set_arr)
result.sort()
for i in result:
    print(i, end=' ')