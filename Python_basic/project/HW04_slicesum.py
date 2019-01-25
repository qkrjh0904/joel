# -*- coding: utf-8 -*-

def main():
    line = input()
    op = input()
    line2 = input()
    rang = input()
    result = 0
    long = 0
    
    words = line.split()
    words2 = line2.split()
    rangs = rang.split()
    
    
    if len(words)>len(words2):
        ns = [0] * len(words)
        ns2 = [0] * len(words)
        summ = [0] * len(words)
        long = len(words)
    else:
        ns = [0] * len(words2)
        ns2 = [0] * len(words2)
        summ = [0] * len(words2)
        long = len(words2)

    ns3 = [0] * len(rangs)
    
    i = 0
    for word in words:
        ns[i] = int(word)
        i += 1
        
    i = 0
    for word in words2:
        ns2[i] = int(word)
        i += 1

    i = 0
    for word in rangs:
        ns3[i] = int(word)
        i += 1


    
    rang1 = ns3[0]
    rang2 = ns3[1]
        
    if op=='+':
        for n in range(0, long):
            summ[n] = ns[n]+ns2[n]
    else:
        for n in range(0, long):
            summ[n] = ns[n]-ns2[n]

    
    for n in range(rang1, rang2):
        result += summ[n]
    print(result)


if __name__ == '__main__':
    main()

