import heapq

from sys import stdin

input = stdin.readline

t = int(input())
for _ in range(t):
    k = int(input())
    min_heap = []  # 최소힙
    max_heap = []  # 최대힙
    count = {}  # 각 숫자의 등장 횟수를 추적하는 딕셔너리
    for _ in range(k):
        cmd, n = input().split()
        n = int(n)
        
        if cmd == 'I':  # 값 삽입
            heapq.heappush(min_heap, n)  # 최소힙에 삽입
            heapq.heappush(max_heap, -n)  # 최대힙은 음수로 삽입 (최대값을 구하기 위해)
            count[n] = count.get(n, 0) + 1
        
        elif cmd == 'D' and count:  # 값 삭제
            if n == -1:  # 최소값 삭제
                while min_heap and count.get(min_heap[0], 0) == 0:  # 사용되지 않은 최소값 삭제
                    heapq.heappop(min_heap)
                if min_heap:
                    val = heapq.heappop(min_heap)
                    count[val] -= 1  # 삭제된 값의 개수 줄임
            elif n == 1:  # 최대값 삭제
                while max_heap and count.get(-max_heap[0], 0) == 0:  # 사용되지 않은 최대값 삭제
                    heapq.heappop(max_heap)
                if max_heap:
                    val = -heapq.heappop(max_heap)
                    count[val] -= 1  # 삭제된 값의 개수 줄임
    
    # 최종 출력
    while min_heap and count.get(min_heap[0], 0) == 0:  # 사용되지 않은 최소값 삭제
        heapq.heappop(min_heap)
    
    while max_heap and count.get(-max_heap[0], 0) == 0:  # 사용되지 않은 최대값 삭제
        heapq.heappop(max_heap)
    
    if min_heap and max_heap:
        print(-max_heap[0], min_heap[0])  # 최대값과 최소값 출력
    else:
        print('EMPTY')