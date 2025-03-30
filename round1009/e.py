from random import randint

def ask(i, j, k):
    print(f"? {i} {j} {k}")
    return int(input())

def answer(i, j, k):
    print(f"! {i} {j} {k}")

t = int(input())
for _ in range(t):
    n = int(input())
    i = [1, 2, 3]
    for iteration in range(100):
        p = ask(i[0], i[1], i[2])
        if p == 0:
            answer(i[0], i[1], i[2])
            break
        i[randint(0, 2)] = p
