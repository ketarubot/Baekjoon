e, s, m = map(int, input().split())
count = 1
while not (e == 1 and s == 1 and m == 1):
     e = 15 if e==1 else e-1
     s = 28 if s==1 else s-1
     m = 19 if m==1 else m-1
     count+=1
print(count)