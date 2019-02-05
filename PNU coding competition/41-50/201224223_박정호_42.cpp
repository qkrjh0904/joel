#include <iostream>

using namespace std;

int solution(int n){
    int answer=0;
	
	int one_num=0;	//이진수에서 1의 개수 
	int num = n;	
	while(num!=0){	//1의 개수 계산 
		if(num%2 == 1)
			one_num++;
		num /= 2;
	}
//	cout<<one_num<<endl;
	
	int big_one_num=0; 	//다음 큰수의 이진수에서 1의개수
	int big_num=n;
	while(one_num != big_one_num){	//1의 개수는 같으면서 n보다 큰 최솟값. 
		big_num++;
		num = big_num;
		big_one_num=0;
//		cout<<big_num<<"의 1의 개수 : "; 
		while(num!=0){	//1의 개수 계산 
			if(num%2 == 1)
				big_one_num++;
			num /= 2;
		}
//		cout<<big_one_num<<endl;
	}
	answer = big_num;
    return answer;
}

int main(void){

	int n = 78;
	int answer = solution(n);
	cout<< answer <<endl;
	return 0;
} 
