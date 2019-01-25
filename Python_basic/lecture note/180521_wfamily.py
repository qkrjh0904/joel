def wfamily(w1, w2):
    ## w1에서 한자씩 뽑아 내서, w2에서 같은 글자가 있으면 공백으로 처리.
    ## w1과 w2가 모두 같다면 w2는 공백이 되기때문에 공백이면 yes, 아니면 no
    for c in w1:
        w2 = w2.replace(c,"")
    if w2=='':
        print('Yes')
    else:
        print('No')


if __name__=='__main__':
    w1 = 'lots'
    w2 = 'stol'
    wfamily(w1, w2)
