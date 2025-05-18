string = input()
suffixes = []
for i in range(len(string)):
    suffixes.append(string[i:])
print('\n'.join(sorted(suffixes)))