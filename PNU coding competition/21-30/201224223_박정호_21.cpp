#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool solution(vector<string> s) {
    bool answer = true;	//����Ʈ�� true. 
   	int cnt=0;			//���� ��ġ�ϴ��� ī��Ʈ 
   	for(int i=0; i<s.size(); ++i){	
		for(int j=0; j<s.size(); ++j){
			if(i==j)	//���� ��ȣ ���� 
				continue;
			cnt=0;		//cnt�ʱ�ȭ 
			for(int k=0; k<s[i].size(); ++k){
				if(s[i][k] != s[j][k])	//�ϳ��� �ٸ��� ���������� 
					break;
				cnt++;
				if(cnt==s[i].size())
					return false;	//�ٸ� ��ȣ�� ���ξ� �̹Ƿ� false return 
				
			}
		}  
	}
    
    
    return answer;
}

int main(void){
	
	vector<string> s = {"119","97674223", "1195524421"};
	//	vector<string> s = {"12","123", "1235", "567", "88"};
	//	vector<string> s = {"123","456", "789"};
	bool answer = solution(s);
	cout<< answer <<endl;
	
	
	return 0;
}
