t = int(input())
for _ in range(t):
    n = int(input())
    s = input()
    dash = 0
    under = 0
    for c in s:
        if c == '-':
            dash += 1
        else:
            under += 1
    print(under * (dash // 2) * (dash - dash // 2))
