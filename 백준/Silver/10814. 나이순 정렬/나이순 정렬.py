from sys import stdin
input = stdin.readline

n = int(input())
members = dict()
for _ in range(n):
    age, name= input().split()
    g = int(age)
    if members.get(g, False):
        members[g].append(name)
    else:
        members[g] = list()
        members[g].append(name)

for i in range(1, 201):
    if members.get(i, False):
        for name in members[i]:
            print(i, name)