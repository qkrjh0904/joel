# -*- coding: utf-8 -*-

def main():
    line = input()
    words = line.split()
    ns = [0] * len(words)
    ms = [0] * len(words)
    w = [0] * len(words)
    i = 0
    for word in words:
        ns[i] = int(word)
        ms[i] = int(word)
        if ms[i]<0:
            return print("NEGATIVE")
        i += 1

        
    i=0
    word=0
    for word in words:
        while(ns[i]>9):
            w[i] += ns[i]%10
            ns[i] = int(ns[i]/10)
        w[i] += ns[i]
        i += 1

    sz = len(words)
    i=0
    for n in range(1, sz):
        if i<sz:
            if w[i]>w[i+1]:
                big = ms[i]
            else:
                big = ms[i+1]
            i+=1


    print(big)

        

if __name__ == '__main__':
    main()


