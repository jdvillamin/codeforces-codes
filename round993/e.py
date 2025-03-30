for _ in range(int(input())):
    k, l1, r1, l2, r2 = map(int, input().split())
    answer = 0
    p = 1
    while p <= 1000000000:
        mr2 = (r2 // p) * p
        mr1 = min(r1, (mr2 // p))
        ml2 = ((l2 + p - 1) // p) * p
        ml1 = max(l1, (ml2 // p))
        answer += min(max(0, mr2 - ml2 + 1), max(0, mr1 - ml1 + 1))
        p *= k
    print(answer)
