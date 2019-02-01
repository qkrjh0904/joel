#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool solution(vector<string> s) {
    bool answer = true;	//디폴트값 true. 
   	int cnt=0;			//전부 일치하는지 카운트 
   	for(int i=0; i<s.size(); ++i){	
		for(int j=0; j<s.size(); ++j){
			if(i==j)	//같은 번호 제외 
				continue;
			cnt=0;		//cnt초기화 
			for(int k=0; k<s[i].size(); ++k){
				if(s[i][k] != s[j][k])	//하나라도 다르면 빠져나오기 
					break;
				cnt++;
				if(cnt==s[i].size())
					return false;	//다른 번호의 접두어 이므로 false return 
				
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
