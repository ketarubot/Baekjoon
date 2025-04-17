from itertools import combinations

height = [int(input()) for _ in range(9)]

for case in combinations(height, 7):
    if sum(case) == 100:
        case = list(case)
        case.sort()
        print('\n'.join(map(str, case)))
        break