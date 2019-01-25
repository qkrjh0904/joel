summ=0
count=0

def score(upper, n):
    global summ
    global count
    if n == 0:
        return print(summ)
    c_cur = upper[n-1:n]
    c_pre = upper[n:n+1]
        
    if c_cur == 'O':
        summ += 1
        if c_cur == c_pre:
            count += 1
            summ += count
        else:
            count=0
    n -= 1
    score(upper, n)



result = input()
upper = result.upper()
score(upper, len(upper))
