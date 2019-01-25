# -*- coding: utf-8 -*-

def line1(c, n):
    s = c * n +'+'
    print(s)

def line2(c, n):
    s = c * n +'|'
    print(s)

def line(m):
    if m==1:
        line2('|     ',6)
        line2('|     ',6)
        line1('+-----',6)
    else:
        line2('|     ',6)
        line2('|     ',6)
        line1('+-----',6)
        line(m-1)

m = eval(input())

line1('+-----',6)
print('|     | MON | TUE | WED | THU | FRI |')
line1('+-----',6)

line(m)
