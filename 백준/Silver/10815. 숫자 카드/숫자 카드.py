n = int(input())
having = set(map(int, input().split()))
m = int(input())
examine = list(map(int, input().split()))

print(*(1 if ex in having else 0 for ex in examine))