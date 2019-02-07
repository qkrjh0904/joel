#include <iostream>
#include <cmath> 

using namespace std;

int solution(int n){
	int answer = 0;
	int num=0;
	num = pow(2,n);
	
	while(num!=0){
		answer += (num%10);
		num /= 10;
	}


	return answer;
}

int main(void){
	
	int n = 15;
	int answer = solution(n);
	cout<<answer<<endl;

	
	
	return 0;
}
