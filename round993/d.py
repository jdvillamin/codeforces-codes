"""
m1 m1 ... m1 m2 m2 ... m2 m3 m3 ... m3 ... mk mk ... mk

4 5 5 5 1 1 2 3

4 5 8 7 1 6 2 3
"""

for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    visited = [False] * (n + 1)
    b = [-1] * n
    for i in range(n):
        if visited[a[i]]:
            continue
        visited[a[i]] = True
        b[i] = a[i]
    s = []
    for i in range(1, n + 1):
        if not visited[i]:
            s.append(i)
    for i in range(n):
        if b[i] == -1:
            b[i] = s.pop()
    print(' '.join(list(map(str, b))))
