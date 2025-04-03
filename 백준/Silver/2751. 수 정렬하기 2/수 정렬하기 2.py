import sys as s

n = int(s.stdin.readline())
arr = [int(s.stdin.readline()) for _ in range(n)]
arr.sort()
for i in range(n):
    print(arr[i])