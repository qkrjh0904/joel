#include <iostream>

using namespace std;

long long solution(int a, int b) {
    long long answer = 0;
    long long num=0;
    
    //���� ������ �������ϱ�.
    if(b>a)
		num = b-a+1;
	else
		num = a-b+1;
	
	
	if(num%2==0){	//�� ���� ������ ������ ¦������, �糡 �� �� ���ϱ� ������ ���� ������2 
		answer = (a+b)*(num/2);
	}
	else{			//�� ���� ������ ������ Ȧ������, �糡 �� �� X ������ ����/ 2 + �߰��� 
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
