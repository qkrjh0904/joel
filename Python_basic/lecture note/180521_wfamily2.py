def clist(w1):
    ls1 = []
    for c in w1:
        ls1.append(c)
    ls1.sort()
    return ls1
    
    return sorted([c for c in w1])
    return sorted(w1)


if __name__=='__main__':
    w1 = 'boys'
    w2 = 'byso'
    if clist(w1)==clist(w2):
        print('Yes')
    else:
        print('No')
