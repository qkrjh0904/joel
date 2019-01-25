#-*- coding: euckr -*-

def main():
    str1 = input()
    name = input()
    list1 = str1.split()
    nlist = name.split()

    transtab = {list1[0]:"0", list1[1]:"1", list1[2]:"2", list1[3]:"3",
                list1[4]:"4", list1[5]:"5", list1[6]:"6", list1[7]:"7",
                list1[8]:"8", list1[9]:"9"}
    
            
    list2 = []
    for word in nlist:
        if word in transtab:
            list2.append(transtab[word])
        else:
            list2.append(word)
    con = ""
    str2 = con.join(list2)

    V = int(str2)**2
    print(V)
    

if __name__ == '__main__':
    main()
