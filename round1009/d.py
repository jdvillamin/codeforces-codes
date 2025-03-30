from math import isqrt

t = int(input())
for _ in range(t):
    n, m = map(int, input().split())
    x = list(map(int, input().split()))
    r = list(map(int, input().split()))
    p = {}
    for i in range(n):
        for j in range(x[i] - r[i], x[i] + r[i] + 1):
            p[j] = 0
    for i in range(n):
        for j in range(x[i] - r[i], x[i] + r[i] + 1):
            p[j] = max(p[j], 2 * isqrt(r[i] * r[i] - (x[i] - j) * (x[i] - j)) + 1)
    print(sum(p.values()))
