## Just Enter 'Hello World !' as an input
string = input()     	
print(string.upper())
print(string.lower())
print(string.count("l"))
list = string.split()
print(list)
#첫번째 알파벳?
print(list[0].isalpha())
#마지막 알파벳?
print(list[-1].isalpha())
#첫번째 혹은 마지막 알파벳?
print(list[-1][0].isalpha())    
print(ord(list[-1][0])-ord('A'))
print([0]*5)

