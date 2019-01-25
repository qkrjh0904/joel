def star_h(n):
    a = int(n/6)
    b = int(n/5)
    d = int(n/5)
    e = int(n/6)
    c = n-a-b-d-e
    
    for i in range(0,int(n/9)):
        for j in range(0, a):
            print(' ', end='')
        for j in range(0, b):
            print('*', end='')
        for j in range(0, c):
            print(' ', end='')
        for j in range(0, d):
            print('*', end='')
        for j in range(0, e):
            print(' ', end='')
        a -= 2
        b += 4
        c -= 4
        d += 4
        e -= 2
        print()

def star_t(n):
    a = 0
    b = 4*n-3
    for i in range(n):
        for j in range(0, a):
            print(' ', end='')
        for j in range(0, b):
            print('*', end='')
        a += 2
        b -= 4
        print()


n = input()
star_h(eval(n)*4-2)
star_t(eval(n))
print("♥ 복 어 힘 내 ♥")
print("ㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋ")
