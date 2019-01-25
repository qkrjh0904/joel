i=0
summ=0
count=0
def score(upper, n):
    global summ
    global count
    global i
    for i in range(n):
        c_cur = upper[i:i+1]
        c_pre = upper[i-1:i]
        if c_cur == 'O':
            summ += 1
            if c_cur == c_pre:
                count += 1
                summ += count
            else:
                count=0
    print(summ)



result = input()
upper = result.upper()
score(upper, len(upper))

