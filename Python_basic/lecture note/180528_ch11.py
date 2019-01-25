class Matrix:
    def __init__(self, rows):
        self.elems = rows
        
    def printMat2(self):
        for row in self.elems:
            for elem in row:
                print(elem, end=" ")
            print()
            
    def __repr__(self):
        rowstrs = []
        for row in self.elems:
            rowstr = [str(n) for n in row]
            rowstrs.append('['+','.join(rowstr)+']')
        mstr = '['+','.join(rowstrs)+']'
        return 'Matrix('+mstr+')'
        
    def __str__(self):
        rowstrs = []
        for row in self.elems:
            rowstr = [str(n) for n in row]
            rowstrs.append(' '.join(rowstr))
        return '\n'.join(rowstrs)
    
    def __getitem__(self, i):
        return self.elems[i]


##  matrix 출력 함수1
def printMat1(m):
    for row in m:
        print(row)

##  matrix를 list형태를 없애고 출력
def printMat2(m):
    for row in m:
        for elem in row:
            print(elem, end=" ")
        print()

##  순서대로 봐
def main():
    m = [[i+1]*3 for i in range(2)]
    
    print(m)
    print()
    ##  Function
    print('This is Function')
    printMat1(m)
    printMat2(m)
    print()

    ##  Class-Method
    print('This is Class-Method')
    m = Matrix([[i+1]*3 for i in range(2)])
    m.printMat2()
    print()
    
    print('1')
    m2 = Matrix([[1,2],[3,4]])
    m2.printMat2()
    print()

    ## print(m2.__str__()) == print(m2)
    print('2')
    print(m2.__str__())
    print()
    print('3')
    print(m2)
    print()
    print('4')
    print(m2[0])
    print()
    
    print(m2.__repr__())
    m2repr = m2.__repr__()
    m3 = eval(m2repr)
    print(m3)
    print(m3.__repr__())
    


    
if __name__ == '__main__':
    main()
