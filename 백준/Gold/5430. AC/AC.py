from sys import stdin
from ast import literal_eval
from collections import deque
input = stdin.readline

t = int(input())
for i in range(t):
    p = input().strip()
    n = int(input())
    arr = deque(literal_eval(input().strip()))
    error = False
    reverse = False
    for cmd in p:
        if cmd == 'R':
            reverse = not reverse
        elif cmd == 'D':
            if arr:
                if reverse:
                    arr.pop()
                else:
                    arr.popleft()
            else:
                error = True
        if error:
            break
    if error:
        print('error')
    else:
        if reverse:
            arr.reverse()
        print("[" + ",".join(map(str, arr)) + "]")