ln = input()
sn = ln[0]
for idx, ch in enumerate(ln[1:]):
    if ch == '-':
        sn += ln[idx+2]
print(sn)