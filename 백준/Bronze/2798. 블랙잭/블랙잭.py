from itertools import combinations

n, m = map(int, input().split())
cards = list(map(int, input().split()))
result = 0

for case in combinations(cards, 3):
    temp = sum(case)
    if result < temp <= m:
        result = temp

print(result)