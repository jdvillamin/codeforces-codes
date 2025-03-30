for _ in range(int(input())):
    a = input()[::-1]
    for c in a:
        l = c
        if c == 'p':
            l = 'q'
        elif c == 'q':
            l = 'p'
        print(l, end='')
    print()  
