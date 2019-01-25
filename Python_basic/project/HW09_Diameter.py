from math import *
import sys

class Point:
    def __init__(self, mat):
        self.elems = mat

    def dist(self):
        mat = self.elems
        leng = len(mat)
        
        dmat=[0]*leng
        maxl=[0]*leng
        for i in range(leng):
            for j in range(leng):
                d = sqrt((mat[i][0]-mat[j][0])**2 + (mat[i][1]-mat[j][1])**2)
                dmat[j] = round(d, 2)
            maxl[i] = max(dmat)
            print(dmat)
        print()
        print(maxl)
        print("%.2f" % max(maxl))

def main():
    mat = []
    for line in sys.stdin:
        line = list(map(float, line.split()))
        mat.append(line)
    mat.sort()
    
    m = Point(mat)
    m.dist()
    
if __name__ == '__main__':
    main()
