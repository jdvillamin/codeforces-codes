t = int(input())
for _ in range(t):
    n, k, p = map(int, input().split())
    k = abs(k)
    p = abs(p)
    answer = (k + p - 1) // p
    if answer > n:
        print(-1)
    else:
        print(answer)
