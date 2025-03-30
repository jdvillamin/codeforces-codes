for _ in range(int(input())):
    m, a, b, c = map(int, input().split())
    r1 = min(m, a)
    r2 = min(m, b)
    left = m - r1 + m - r2
    answer = r1 + r2 + min(left, c)
    print(answer)
