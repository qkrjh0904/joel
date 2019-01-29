#include <iostream>
#include <string>

using namespace std;

string solution(string s){
	int sleng = s.length();	//입력 단어 길이 측정 
	
	while(sleng>2){		//입력단어가 2자리 이하면 그대로 반환하고, 2자리보다 크면 아래 코드 실행 
		s.erase(0, 1);			//입력단어에서 첫번째 문자 지움. 
		s.erase(sleng-2, 1);	//입력단어에서 마지막 문자 지움. 
		
		sleng = s.length();		//양 끝 문자 지운 후 다시 문자길이 측정. 
	}
	
	return s;
}

int main(void){
	
	string s = "QWER";	//입력 단어 예시 
	
	string result;
	result = solution(s);
	
	cout<< result <<endl;
	
	
	
	return 0;
}
