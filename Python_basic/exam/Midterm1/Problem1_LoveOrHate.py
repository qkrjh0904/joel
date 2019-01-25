def choose(num, count, word1, word2):
    if num == 0:
        if count%2==1:
            return print(word1)
        else:
            return print(word2)
    else:
        choose(num-1, count+1, word1, word2)





num = eval(input())
word1 = input()
word2 = input()
count = 0

result = choose(num, count, word1, word2)
