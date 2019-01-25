#-*- coding: utf-8 -*-

def stair(n):   #stair함수 정의
    if n==0 or n==1:    # n이 0이거나 1이면 1 리턴
        return 1
    #현재 n계단이 있다면 계단의 수가 n-1일때와 n-2일때의
    #합이 n개의 개수가 된다.
    else:       
        return stair(n-1) + stair(n-2)



def main():
    n = int(input())    # n을 입력 받음
    print(stair(n))     # stair(n)을 출력

if __name__ == '__main__':
    main()
