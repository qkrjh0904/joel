import sys

def maxx(row, col, summ):
##    maxv = summ[0]
##    for i in range(1, len(summ)):
##        if maxv < summ[i]:
##            maxv = summ[i]
    maxv = max(summ)
    loc = summ.index(maxv)
    x = loc%col
    y = int(loc/col)
    print(x, y)
    
def neighbors(mat):
    row = len(mat)
    col = len(mat[0])
    size = row*col
    summ = [0]*size

    x=0
    y=0
    for i in range(size):
        if x!=0:
            summ[i] += mat[y][x-1]
            if y!=0:
                summ[i] += mat[y-1][x-1]
        if y!=0:
            summ[i] += mat[y-1][x]
            if x!=(col-1):
                summ[i] += mat[y-1][x+1]
        if x!=(col-1):
            summ[i] += mat[y][x+1]
            if y!=(row-1):
                summ[i] += mat[y+1][x+1]
        if y!=(row-1):
            summ[i] += mat[y+1][x]
            if x!=0:
                summ[i] += mat[y+1][x-1]
        x += 1
        if x==col:
            y += 1
            x = 0
    maxx(row, col, summ)
    
def main():
    mat = []
    for line in sys.stdin:
        line = list(map(int, line.split()))
        mat.append(line)
    neighbors(mat)

if __name__=='__main__':
    main()
