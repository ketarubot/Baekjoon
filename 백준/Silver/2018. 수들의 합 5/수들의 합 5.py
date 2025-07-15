n = int(input())
start = 1
end = 1
count = 0
while start <= end:
    sum = (end*(end+1) - (start-1)*start) // 2
    if sum < n: end += 1
    elif sum > n:
        start += 1
        end = start
    else:
        count += 1
        start += 1
print(count)