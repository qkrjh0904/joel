def transpose(mat):
    row = len(mat)
    col = len(mat[0])
    mat3 = [[0]*row for i in range(col)]
    for i in range(row):
        for j in range(col):
            mat3

def filterNeg(mat):
    row = len(mat)
    col = len(mat[0])
    mat2 = [[0]*col for i in range(row)]
    for i in range(row):
        for j in range(col):
            if mat[i][j] < 0:
                mat2[i][j] = 0
            else:
                mat2[i][j] = mat[i][j]
    return mat2

def main():
    row = 2
    col = 3
    mat = [[0]*col for i in range(row)]
    print(mat)
    initlist = [1, 9, -12, 20, -5, 7]
    k = 0
    for i  in range(row):
        for j in range(col):
            mat[i][j] = initlist[k]
            k += 1
    print(mat)
    mat2 = filterNeg(mat)
    print(mat2)
    


if __name__ == '__main__':
    main()
