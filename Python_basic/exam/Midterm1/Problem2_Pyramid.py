def printPyramid(n, c):
    a = n-1
    b = 1
    for i in range(n):
        for j in range(0, a):
            print(' ', end='')
        for j in range(0, b):
            print(c, end='')
        a -= 1
        b += 2
        print()






n = eval(input())
c = input()

printPyramid(n, c)
