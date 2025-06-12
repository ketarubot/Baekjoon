for _ in range(int(input())):
    ps = input()
    isVps = True
    lp = 0
    for p in ps:
        if p == '(': lp+=1
        elif p == ')' and lp > 0: lp-=1
        else:
            isVps = False
            break
    if lp > 0: isVps = False
    print('YES' if isVps else 'NO')