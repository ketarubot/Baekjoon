s = input()
count = [0 for _ in range(0,26)]
for char in s:
    count[ord(char)-97] += 1
print(' '.join(map(str, count)))