#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> weight) {
    int answer = 1;		//���������� ���� �������� 1���� ����.
	
	sort(weight.begin(), weight.end());	//������� ����. 
//	for(int i=0; i<weight.size(); ++i)
//		cout<< weight[i] << ' ';
//	cout<<endl;

    int max=0;	//�� �� �ִ� ���� ū ��. 
    for(int i=0; i<weight.size(); ++i)
    	max += weight[i];
    
	//���� ���� 1���� max�������� �ݺ��Ͽ� ã��.	
    for(int i=1; i<max; ++i){
		
	}
    
    
    return answer;
}

int main(void){

	vector<int> weight = {3,1,6,2,7,30,1};
	int answer = solution(weight);
	cout<< answer <<endl;
	
	return 0;
}
