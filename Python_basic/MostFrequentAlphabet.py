string = input()
string = string.replace(' ','')

#모두 소문자가 맞는지 확인 아니면 에러
if string.islower() == False:
    print('ERROR')
#모두 알파벳이 맞는지 확인 아니면 에러
elif string.isalpha() == False:
    print('ERROR')

else:
    #알파벳 갯수 세기
    num = ord('z')-ord('a')+1
    cnt = num*[0]
    for i in string:
        cnt[ord(i)-ord('a')] = string.count(i)
        
    #count해서 가장 많이 나온 알파벳 개수 저장
    m = max(cnt)

    #가장 많이 나온 알파벳 찾기
    i=0
    while i < len(cnt):
        if cnt[i] == m:
            print(chr(i+ord('a')))
            break
        else:
            i += 1

