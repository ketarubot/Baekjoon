n, m = map(int, input().split())

seq = []

output = []
def dfs(depth):
    if depth == m:
        output.append(' '.join(map(str, seq)))
        return

    for i in range(1, n+1):
        seq.append(i)
        dfs(depth + 1)
        seq.pop()

dfs(0)

print('\n'.join(output))