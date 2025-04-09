word = input()
count = [0 for _ in range(0,26)]
for i in word:
    if i.isupper():
        count[ord(i)-65] += 1
    elif i.islower():
        count[ord(i)-97] += 1
max_idx = count.index(max(count))
max_var = count.pop(max_idx)
if max_var in count:
    print('?')
else:
    print(chr(max_idx + 65))