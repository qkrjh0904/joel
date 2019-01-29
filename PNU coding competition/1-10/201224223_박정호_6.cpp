#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
	string ans = "";
	
	//�����ڿ� ����� ���ĺ��� ���� 
	sort(participant.begin(), participant.end());
	sort(completion.begin(), completion.end());

	//��Ȯ�� sort�Ǿ����� Ȯ��. 
//	for(int i=0; i<participant.size(); ++i)
//		cout<<participant[i]<<' ';
//	cout<<endl;
//	for(int i=0; i<completion.size(); ++i)
//		cout<<completion[i]<<' ';
//	cout<<endl;
	
	//������ �� �Ѹ� �����߱� ������ �����ڿ� ����� ���� �ٸ���� �������� ��ܿ� �ִ� ����� �����ڴ�. 
	for(int i=0; i<completion.size(); ++i){		//����� ��� ����ŭ �� 
		if(participant[i] != completion[i]){	//�����ڿ� ����� ����� �ٸ���� ������ ��� return. 
			ans = participant[i];
			return ans;
		}
	}
	//����� ����� �� ������ return���� �ʾҴٸ�, ������ ����� �������� �ִ� ����̴�. 
	ans = participant[participant.size()-1];	
    return ans;
}

int main(void){
	
	vector<string> participant = {"leo", "kiki", "eden"};
	vector<string> completion = {"eden", "kiki"};
	
	string ans = solution(participant, completion);
	cout<< ans <<endl;

	return 0;
}
