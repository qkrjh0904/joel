#include <iostream>
#include <string>

using namespace std;

string solution(string s) {
    string answer = "";
    
    int index=1;	//���� ó�� index�� 1�� ���� 
    for(int i=0; i<s.size(); ++i){	//���ڿ� ���̸�ŭ �ݺ� 
		if(s[i] == ' '){	//�������Ŀ� ���� index�� �����ؾ��ϹǷ� 0���� ���� 
			index = 0;
		}
		
		if(index%2 == 1){	//index�� Ȧ����°�϶�, �빮��. 
			if(s[i]>=97 && s[i]<=122)
				s[i] -= 32;
			answer += s[i];
		}
		else{	//index�� ¦����°�϶�, �ҹ���. ����� �״�� �Է�. 
			if(s[i]>=65 && s[i]<=90)
				s[i] += 32;
			answer += s[i];
		}
		index++;
	}
    return answer;
}

int main(void){
	
	string s = "try hello world";
	string answer = solution(s);
	cout<< answer <<endl;

	return 0;
}
