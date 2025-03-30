t = int(input())
for _ in range(t):
    l, r, d, u = map(int, input().split())
    if l == r and r == d and d == u:
        print("Yes")
    else:
        print("No")