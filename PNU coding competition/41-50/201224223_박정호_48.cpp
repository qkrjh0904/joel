#include <iostream>
#include <string>

using namespace std;

string solution(int n) {
    string answer = "";
	
	for(int i=0; i<n/2; ++i)
		answer += "¼ö¹Ú";
	if(n%2==1)
		answer += "¼ö"; 
    
    
    return answer;
}

int main(void){
	
	int n = 4;
	
	string answer = solution(n);
	cout<< answer <<endl;


	return 0;
}
