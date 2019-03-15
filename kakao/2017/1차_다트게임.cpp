#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string dartResult) {
    vector<string> n(3);  //�� ��Ʈ���� ���� ����
    vector<char> b(3);  //�� ��Ʈ�� ���ʽ�
    vector<char> o(3);  //�� ��Ʈ�� �ɼ�
    int cnt=0;      //dartResult�� ���� ��ġ
    int index=0;    //�� ��Ʈ�� index
    while(true){
        //index�� 3�� �Ѱų�, cnt�� dartResultũ�⺸Ÿ ũ�� break
        if(cnt==dartResult.size() || index==3)
            break;
        //dartResult�� ���ڰ� ���ڸ� n[index]�� �Է�
        if(dartResult[cnt]>='0' && dartResult[cnt]<='9'){
            n[index] += dartResult[cnt];
            cnt++;
            continue;   //10�� ���� ���ڰ� �ΰ��̹Ƿ� �ٽ� �ǵ��ư��� 1���� 0�� �������� �� Ȯ���ؾ���
        }
        if(dartResult[cnt]=='S' || dartResult[cnt]=='D' || dartResult[cnt]=='T'){
            b[index] += dartResult[cnt];
            cnt++;
        }
        if(dartResult[cnt]=='*' || dartResult[cnt]=='#'){
            o[index] += dartResult[cnt];
            cnt++;
        }
        index++;
    }
    //����, ���ʽ�, �ɼ��� ��� �� ��µǾ����� Ȯ�� ���
    for(int i=0; i<3; ++i){
        cout<<n[i]<<' '<<b[i]<<' '<<o[i]<<'\n';
    }
    
    //�⺻����+���ʽ� ����� basic�� �ɼ� ���� ����� mul ���� ����
    vector<int> basic(3);
    vector<int> mul(3);
    //�⺻+���ʽ� ���� ���
    for(int i=0; i<3; ++i){
        int input=stoi(n[i]);
        if(b[i]=='D')   //D�� ����
            input = input*input;
        else if(b[i]=='T')  //T�� ������
            input = input*input*input;
        basic[i] = input;
    }
    //�ɼ����� ���
    for(int i=0; i<3; ++i){
        int input=1;
        if(o[i]=='*'){  
            input *= 2;
            if(i>0)
                mul[i-1] *= 2;  //index�� 1�̻��ΰ�� ������ ������ 2��
        }
        else if(o[i]=='#')
            input *= -1;    //#�̸� �������� -1
        mul[i] = input;
    }
    //basic�� mul�� �� ���Ǿ����� ���
    for(int i=0; i<3; ++i)
        cout<<basic[i]<<' ';
    cout<<endl;
    for(int i=0; i<3; ++i)\
        cout<<mul[i]<<' ';
    cout<<endl;
    
    int answer = 0;
    for(int i=0; i<3; ++i){
        answer += (basic[i]*mul[i]);    //basic�� mul�� ���� ���� ���̵ȴ�.
    }
    return answer;
}
