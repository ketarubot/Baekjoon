from sys import stdin
input = stdin.readline

n = int(input())
words = [input().strip() for _ in range(n)]
len_words = dict()

for word in words:
    l = len(word)
    if len_words.get(l, False):
        if word not in len_words[l]:
            len_words[l].append(word)
    else:
        len_words[l] = list()
        len_words[l].append(word)

sorted_words = list()
for i in range(1,51):
    if len_words.get(i, False):
        len_words[i].sort()
        for word in len_words[i]:
            sorted_words.append(word)

print('\n'.join(map(str, sorted_words)))