import sys
sys.setrecursionlimit(10**6)

n = int(input())
time = list(map(int, input().split()))

def quick_sub(arr, start, end):
    if end - start <= 0: return
    pivot = arr[end]
    i = start
    for j in range(start, end):
        if arr[j] <= pivot:
            arr[i], arr[j] = arr[j], arr[i]
            i += 1
    arr[i], arr[end] = arr[end], arr[i]
    quick_sub(arr, start, i - 1)
    quick_sub(arr, i + 1, end)


def quick(arr):
    quick_sub(arr, 0, len(arr) - 1)

quick(time)
count = 0
for i in range(n):
    count += sum(time[:i+1])
print(count)