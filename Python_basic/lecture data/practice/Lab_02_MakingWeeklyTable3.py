# -*- coding: utf-8 -*-

#문자열 곱하기 숫자 하면 문자열이 그 숫자만큼 반복된다

def line1():
    print('+-----' * 6 +'+')

def line2():
    print('|     ' * 6 +'|')

def line(m):
    if m==1:
        line2()
        line2()
        line1()
    else:
        line2()
        line2()
        line1()
        line(m-1)

m = eval(input())

line1()
print('|     | MON | TUE | WED | THU | FRI |')
line1()

line(m)
