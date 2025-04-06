n = int(input())
n -= 1
room = 1
while n > 0:
    n -= 6 * room
    room += 1
print(room)