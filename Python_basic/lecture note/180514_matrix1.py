m1 = []
for i in range(3):
    m1.append([])
    for j in range(3):
        m1[i].append(i+j)
print(m1)


m2 = [[i+j for j in range(3)] for i in range(3)]
print(m2)
