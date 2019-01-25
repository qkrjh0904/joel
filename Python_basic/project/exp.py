#-*- coding: utf-8 -*-
count = 0
on2=0
r=1
def expo(n1, n2):
    global count
    global r
    global on2
    
    if n2%2==0:
        count += 1
        return n1*n1*expo(n1, int(n2/2))
    else:
        if n2==1:
            return print(r, count)
        count += 1
        return n1*expo(n1, n2-1)

def main():
    global on2
    line = input()
    num = line.split()
    n1 = int(num[0])
    n2 = int(num[1])
    on2 = n2
    expo(n1, n2)

if __name__ == '__main__':
    main()
