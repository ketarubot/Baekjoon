from collections import deque

def merge_sort(item):
    x = len(item)
    if x <= 1:
        return item
    mid = x // 2
    fg = deque(merge_sort(item[:mid]))
    bg = deque(merge_sort(item[mid:]))
    result = []
    while fg and bg:
        if fg[0] < bg[0]:
            result.append(fg.popleft())
        else:
            result.append(bg.popleft())
    while fg:
        result.append(fg.popleft())
    while bg:
        result.append(bg.popleft())
    return result

n = int(input())
nums = [int(input()) for _ in range(n)]
print(round(sum(nums)/n))
sorted_nums = merge_sort(nums)
mid = n//2
if n%2 == 1:
    print(sorted_nums[mid])
else:
    print(sum(sorted_nums[mid-1:mid+1])//2)
count = {}
for num in sorted_nums:
    count[num] = count.get(num, 0) + 1
m = max(count.values())
mc = []
for n, c in count.items():
    if c == m:
        mc.append(n)
print(mc[1] if len(mc) > 1 else mc[0])
print(abs(sorted_nums[-1]-sorted_nums[0]))