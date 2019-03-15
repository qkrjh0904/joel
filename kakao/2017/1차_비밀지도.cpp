#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer(n);
    //���� ũ�⸸ŭ �� ����
    string s;
    for(int i=0; i<n; ++i){
        s += '#';
    }
    //�ϴ� ������ ��� ������ �ʱ�ȭ
    for(int i=0; i<n; ++i){
        answer[i] = s;
    }

    vector<int> map(arr1.size());
    //�� ������ or������ map ���Ϳ� ���������� ����
    for(int i=0; i<map.size(); ++i){
        int x = arr1[i];
        int y = arr2[i];
        int z = x|y;
        map[i] = z;
        //z���
        // cout<<z<<' ';
    }
    // cout<<'\n';
    for(int i=0; i<map.size(); ++i){
        //���ڸ����� ���� 0�̶�� ����κ����� ���������.
        int x = map[i];
        int change = n-1;
        while(true){
            if(x%2==0)
                answer[i][change] = ' ';
            x/=2;
            if(change==0)
                break;
            change--;
        }
    }
    //���� ���
    // for(int i=0; i<n; ++i)
    //     cout<<answer[i]<<' ';
    // cout<<endl;



    return answer;
}
