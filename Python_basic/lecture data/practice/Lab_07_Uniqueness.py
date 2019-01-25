#-*- coding: euckr -*-
def trans(mat):
    row = len(mat)
    col = len(mat[0])
    trans = [[0]*row for i in range(col)]
    for i in range(row):
        for j in range(col):
            trans[j][i]=mat[i][j]
    return trans

def count(row, col, mat):
    ok = 0
    uniq = 0
    for i in range(row):
        for j in range(col):
            ##������ �ϳ��� ������ count=1�̹Ƿ� ok 1����
            count = mat[i].count(mat[i][j])
            if count == 1:
                ok += 1
        #��δ� ���� ok�� 0�ϼ� �����Ƿ�, ok!=0 ���� �߰�
        if ok!=0 and ok%col==0:
            uniq += 1
        ok = 0
    return uniq
            
    

def main():
    num = list(map(int, input().split()))
    row = num[0]
    col = num[1]
    mat = [0]*row
    

    for n in range(row):
        mat[n] = list(map(int, input().split()))

    t_mat = trans(mat)

    
    print(count(row, col, mat)+count(col, row, t_mat))

if __name__ == '__main__':
    main()
