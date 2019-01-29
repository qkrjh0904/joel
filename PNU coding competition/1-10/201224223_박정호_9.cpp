#include <iostream>
#include <string> 
using namespace std;

string solution(string s, int n) {
    string answer = "";
    
    //s의 size 
    int size = s.size();
    for(int i=0; i<size; ++i){	//s 길이만큼 반복
    	if(s[i] == ' ')
    		answer += s[i];
    	else if(s[i]>=65 && s[i]<=90){	//대문자의 경우 
			if(s[i]+n>90)				//n만큼 밀어주고 만약 Z를 넘어가면
				answer += (s[i]+n-26); 		//26만큼 빼 A부터 시작하게함
			else
				answer += (s[i]+n);
		}
		else if(s[i]>=97 && s[i]<=122){	//대문자의 경우 
			if(s[i]+n>122)				//n만큼 밀어주고 만약 z를 넘어가면
				answer += (s[i]+n-26); 		//26만큼 빼 a부터 시작하게함
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
