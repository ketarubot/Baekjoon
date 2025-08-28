import heapq
import sys
input = sys.stdin.readline

min_heap = []
heapq.heapify(min_heap)
for _ in range(int(input())):
    x = int(input())
    if x == 0:
        print(heapq.heappop(min_heap) if min_heap else 0)
        continue
    heapq.heappush(min_heap, x)