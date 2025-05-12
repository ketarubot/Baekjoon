word = input()
count = 0
chroa2 = ['c=', 'c-', 'd-', 'lj', 'nj', 's=', 'z=']
chroa3 = 'dz='
idx = 0
while idx < len(word):
    if word[idx:idx+3] == chroa3:
        idx += 3
    elif word[idx:idx+2] in chroa2:
        idx += 2
    else:
        idx += 1
    count += 1
print(count)