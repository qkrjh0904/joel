#-*- coding: euckr -*-

def main():
    line1 = input().split()
    line2 = input().split()
    line3 = input().split()

    dic = {line1[0]:"0", line1[1]:"1", line1[2]:"2",
           line1[3]:"3", line1[4]:"4", line1[5]:"5",
           line1[6]:"6", line1[7]:"7", line1[8]:"8", line1[9]:"9"}
    dic2 = {0:line1[0], 1:line1[1], 2:line1[2],
            3:line1[3], 4:line1[4], 5:line1[5],
            6:line1[6], 7:line1[7], 8:line1[8], 9:line1[9]}

    ##일치하는 문자나 수 변경.
    val1 = []
    val2 = []
    for word in line2:
        if word in dic:
            val1.append(dic[word])
    for word in line3:
        if word in dic:
            val2.append(dic[word])

    con = ""
    val1 = int(con.join(val1))
    val2 = int(con.join(val2))
        
    summ = val1+val2

    trans = []
    while summ>9:
        trans.append(summ%10)
        summ = int(summ/10)
    trans.append(summ)
    trans.reverse()

    result = []
    for word in trans:
        if word in dic2:
            result.append(dic2[word])
            
    print(" ".join(result))

    

if __name__ == '__main__':
    main()
