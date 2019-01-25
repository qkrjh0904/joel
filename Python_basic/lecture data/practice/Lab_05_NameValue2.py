#-*- coding: euckr -*-

def main():
    input1 = input()
    input2 = input()
    line1 = input1.split()
    line2 = input2.split()

    
    dic = {line1[0]:"0", line1[1]:"1", line1[2]:"2",
           line1[3]:"3", line1[4]:"4", line1[5]:"5",
           line1[6]:"6", line1[7]:"7", line1[8]:"8", line1[9]:"9"}

    value = []
    for word in line2:
        if word in dic:
            value.append(dic[word])
            
    print(value)
    con=""
    value = con.join(value)
    print(int(value)**2)
    

if __name__ == '__main__':
    main()
