n = int(input())
needs = list(input().split())
actual = list(input().split())
for need in needs:
    if need not in actual:
        print(need)
        break