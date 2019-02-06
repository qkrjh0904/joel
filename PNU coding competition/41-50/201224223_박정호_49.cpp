#include <iostream>
#include <string>

using namespace std;

string solution(string s) {
    string answer = "";
    
    int index=1;	//가장 처음 index는 1로 설정 
    for(int i=0; i<s.size(); ++i){	//문자열 길이만큼 반복 
		if(s[i] == ' '){	//띄어쓰기이후에 새로 index를 측정해야하므로 0으로 설정 
			index = 0;
		}
		
		if(index%2 == 1){	//index가 홀수번째일때, 대문자. 
			if(s[i]>=97 && s[i]<=122)
				s[i] -= 32;
			answer += s[i];
		}
		else{	//index가 짝수번째일때, 소문자. 띄어쓰기는 그대로 입력. 
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
