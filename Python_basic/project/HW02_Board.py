# -*- coding: utf-8 -*-

#문자열 곱하기 숫자 하면 문자열이 그 숫자만큼 반복된다

def board(row, col):
    if row>0:
        print('+---' * col + '+')
        print('|   ' * col + '|')
        board(row-1, col)
    else:
        print('+---' * col + '+')

row = eval(input())
col = eval(input())

board(row, col)
