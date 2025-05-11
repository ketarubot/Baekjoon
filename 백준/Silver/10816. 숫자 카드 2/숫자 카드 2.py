input()
having = list(map(int, input().split()))
input()
query = list(map(int, input().split()))
count = dict()
for num in having:
    count[num] = count.get(num, 0) + 1
print(' '.join(str(count.get(q, 0)) for q in query))