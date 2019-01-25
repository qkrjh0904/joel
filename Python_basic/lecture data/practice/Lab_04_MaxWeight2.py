# -*- coding: utf-8 -*-
def maxw(summ):
    ##합이 가장크면서 가장 뒤에있는 위치값
    maxw = summ[0]
    count=0
    i=0
    for i in range(len(summ)):
        if summ[i]>=maxw:
            maxw=summ[i]
            count=i
    return count
            
    
def summ(num):  ##각자리수 합
    summ=[0]*len(num)
    i=0
    for n in num:
        while n>=10:
            summ[i] += n%10
            n = int(n/10)
        summ[i] += n
        i += 1
    return maxw(summ)
    

def main():
    line = input()
    words = line.split()
    num = [0]*len(words)
    i=0
    for word in words:
        num[i] = int(word)
        if num[i]<0:
            return print('NEGATIVE')
        i+=1

    print(num[summ(num)])

if __name__ == '__main__':
    main()

