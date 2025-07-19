s = list(map(int, input()))
count0 = 0
count1 = 0
current = s[0]
for i in range(1, len(s)):
    if s[i] != current:
        if current == 0:
            count0 += 1
            current = 1
        else:
            count1 += 1
            current = 0
if current == 0: count0 += 1
else: count1 += 1
if count0 <= count1: print(count0)
else: print(count1)