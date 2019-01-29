#include <iostream>

using namespace std;

long long solution(int a, int b) {
    long long answer = 0;
    long long num=0;
    
    //정수 사이의 개수구하기.
    if(b>a)
		num = b-a+1;
	else
		num = a-b+1;
	
	
	if(num%2==0){	//두 정수 사이의 개수가 짝수개면, 양끝 수 합 곱하기 정수의 개수 나누기2 
		answer = (a+b)*(num/2);
	}
	else{			//두 정수 사이의 개수가 홀수개면, 양끝 수 합 X 정수의 개수/ 2 + 중간수 
		answer = (a+b)*(num/2) + (a+b)/2;
	}
    
    return answer;
}

int main(void){
	
	long long a = 3;
	long long b = 5;

	long long answer = solution(a,b);
	cout<< answer <<endl;
	
	return 0;
}
