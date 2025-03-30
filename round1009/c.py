def accept(b):
    n = len(b)
    count = 0
    for i in range(n):
        if b[i] == '1':
            b[i] = '0'
        else:
            b[i] = '1'
    for i in range(1, n):
        if b[i] == '0':
            b[i] = '1'
            break
    y = int(''.join(b), 2)
    return y   

t = int(input())
for _ in range(t):
    x = int(input())
    b = list(bin(x)[2:])
    y = accept(b)
    if x <= y or x + y <= (x ^ y) or x + (x ^ y) <= y or y + (x ^ y) <= x:
        print(-1)
    else:
        print(y)