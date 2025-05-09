from sys import stdin
input = stdin.readline

n = int(input())
count = 0
for _ in range(n):
    word = input().strip()
    alp = [0] * 26
    isgroup = True
    for idx, ch in enumerate(word):
        x = ord(ch) - 97
        if idx > 0:
            if alp[x] >= 1 and not ch == word[idx-1]:
                isgroup = False
                break
        alp[x] += 1
    if isgroup:
        count += 1
print(count)