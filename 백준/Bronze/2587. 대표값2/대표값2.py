numbers = [int(input()) for _ in range(5)]
numbers.sort()
avg = sum(numbers) // 5
mid = numbers[2]
print(avg, mid, sep='\n')