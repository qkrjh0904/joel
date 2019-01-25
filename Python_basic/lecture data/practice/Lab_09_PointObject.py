from math import *
import sys

class Point:
    def __init__(self, mat):
        self.elems = mat

    def dist(self):
        leng = len(self.elems)
        i=0
        result = [0]*leng
        for n in self.elems:
            summ = n[0]**2 + n[1]**2
            result[i] = sqrt(summ)
            i+=1
        maxpoint = result[0]
        for i in range(1,leng):
            if result[i]>maxpoint:
                maxpoint = result[i]
        loc = result.index(maxpoint)
        
        print("(%.2f,%.2f)" % (self.elems[loc][0],self.elems[loc][1]))
        print("%.2f" % maxpoint)

def main():
    mat = []
    for line in sys.stdin:
        line = list(map(float, line.split()))
        mat.append(line)
    mat.sort()
    mat.reverse()
    m = Point(mat)    
    m.dist()

if __name__ == '__main__':
    main()

