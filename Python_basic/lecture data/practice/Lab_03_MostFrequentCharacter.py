string = input()
list = string.split()

for n in range(len(list)):
    if not (list[n].islower()) or (list[n].isalpha()):
        print('ERROR')
        break
    else if not (list[n].isalpha()):
        print('ERROR')
        break
    else:
        from collections import Counter
        counter = Counter(string)
        print(max(string, key=counter.get))

