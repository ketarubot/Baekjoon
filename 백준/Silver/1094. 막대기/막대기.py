def find_min_idx(arr):
    min_idx = 0
    for i in range(1, len(arr)):
        if arr[min_idx] > arr[i]:
            min_idx = i
    return min_idx

x = int(input())
having = [64]
while sum(having) > x:
    idx = find_min_idx(having)
    having[idx] //= 2
    having.insert(idx+1, having[idx])
    n = sum(having) - having[idx]
    if n >= x:
        having.pop(idx)
print(len(having))