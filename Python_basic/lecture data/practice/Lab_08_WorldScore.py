from functools import reduce
print(reduce(lambda x,y:x+y, [ord(n) for n in list(input().upper().replace(" ",""))]))


##line = list(input().upper().replace(" ",""))
##print(line)
##asc = []
##for n in line:
##    asc.append(ord(n))
##print(asc)
##from functools import reduce
##print(reduce(lambda x,y:x+y, asc))
