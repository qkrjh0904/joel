#include <iostream>

using namespace std;

int solution(int n){
    int answer=0;
	
	int one_num=0;	//���������� 1�� ���� 
	int num = n;	
	while(num!=0){	//1�� ���� ��� 
		if(num%2 == 1)
			one_num++;
		num /= 2;
	}
//	cout<<one_num<<endl;
	
	int big_one_num=0; 	//���� ū���� ���������� 1�ǰ���
	int big_num=n;
	while(one_num != big_one_num){	//1�� ������ �����鼭 n���� ū �ּڰ�. 
		big_num++;
		num = big_num;
		big_one_num=0;
//		cout<<big_num<<"�� 1�� ���� : "; 
		while(num!=0){	//1�� ���� ��� 
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
