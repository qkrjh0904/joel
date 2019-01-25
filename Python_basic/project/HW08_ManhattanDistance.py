def dist(x1, y1, x2, y2):
    x = x1-x2
    y = y1-y2
    if x<0:
        x *= -1
    if y<0:
        y *= -1
    return print(x+y)

def location(row, col, n1, n2, lines):
    loc1 = lines.index(n1)
    loc2 = lines.index(n2)

    x1 = loc1%col
    y1 = int(loc1/col)
    x2 = loc2%col
    y2 = int(loc2/col)
    
    dist(x1, y1, x2, y2)


def line(row, col, mat):
    size = row*col
    line = [0]*size
    
    k = 0
    for i in range(row):
        for j in range(col):
            line[k] = mat[i][j]
            k+=1
    return line


def main():
    num = list(map(int, input().split()))
    row = num[0]
    col = num[1]
    n1 = num[2]
    n2 = num[3]
    mat = [0]*row

    for n in range(row):
        mat[n] = list(map(int, input().split()))
 
    lines = line(row, col, mat)
    location(row, col, n1, n2, lines)
    
    

if __name__ == '__main__':
    main()
