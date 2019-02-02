#include <iostream>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 1;
    
    stack<string> s;

	if(n==1)
		answer = 1;
	
	answer = solution(n-1)*3-1;
    return answer;
}

int main(void){
	int n = 4;
	int answer = solution(n);
	
	cout<< answer <<endl;
	
	return 0;
}
