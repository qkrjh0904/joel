#-*- coding: euckr -*-

def main():
    v1 = input().split()
    op = input()
    v2 = input().split()
    sl = input().split()

    start = int(sl[0])
    end = int(sl[1])
    leng = end-start

    v1_sl = v1[start:end]
    v2_sl = v2[start:end]

    result = [0]*leng
    summ = 0
    for i in range(leng):
        if op=='+':
            result[i] = int(v1_sl[i])+int(v2_sl[i])
        elif op=='-':
            result[i] = int(v1_sl[i])-int(v2_sl[i])
        summ += result[i]
    
    print(summ)
    

if __name__ == '__main__':
    main()
