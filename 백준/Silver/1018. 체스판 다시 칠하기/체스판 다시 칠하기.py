n, m = map(int, input().split())
board = [input() for _ in range(n)]
min_count = float('inf')
for sr in range(n-7):
    for sc in range(m-7):
        b = 'B'
        w = 'W'
        bsc = wsc = 0
        for i in range(8):
            for j in range(8):
                current = board[sr+i][sc+j]
                if current != b: bsc+=1
                else: wsc+=1
                b, w = w, b
            b, w = w, b
        if bsc < min_count or wsc < min_count:
            min_count = min(bsc, wsc)
print(min_count)