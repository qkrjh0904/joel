#include <iostream>
#include <string> 
using namespace std;

string solution(string s, int n) {
    string answer = "";
    
    //s�� size 
    int size = s.size();
    for(int i=0; i<size; ++i){	//s ���̸�ŭ �ݺ�
    	if(s[i] == ' ')
    		answer += s[i];
    	else if(s[i]>=65 && s[i]<=90){	//�빮���� ��� 
			if(s[i]+n>90)				//n��ŭ �о��ְ� ���� Z�� �Ѿ��
				answer += (s[i]+n-26); 		//26��ŭ �� A���� �����ϰ���
			else
				answer += (s[i]+n);
		}
		else if(s[i]>=97 && s[i]<=122){	//�빮���� ��� 
			if(s[i]+n>122)				//n��ŭ �о��ְ� ���� z�� �Ѿ��
				answer += (s[i]+n-26); 		//26��ŭ �� a���� �����ϰ���
			else
				answer += (s[i]+n);
		}
	}
    
    return answer;
}

int main(void){
	
	string s = "a B z";
	int n = 4;
	
	string answer = solution(s, n);
	cout<< answer <<endl;
	
	return 0;
}
