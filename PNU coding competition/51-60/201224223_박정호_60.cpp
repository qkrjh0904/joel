#include <iostream>
#include <vector>

using namespace std;

int solution(int num){
	int answer = 0;
	int n = num;	//num�̸��� ����. 
	//����+������+������ ���� ������ ���� ū �Ҽ��� 67�̴�.	
	vector<int> prime = {2};		//67������ �Ҽ� ����
	for(int i=3; i<=67; i+=2){		//Ȧ���� ��� 
		prime.push_back(i);
		for(int j=3; j<i-1; j+=2){	//¦���� Ȧ���� ����� �� �� �����Ƿ� j+=2. 
			if(i%j==0){
				prime.pop_back();
				break;
			}
		}
	}
	int size = prime.size();
	//�Ҽ� ���. 
//	for(int i=0; i<size; ++i)
//		cout<<prime[i]<<' ';
//	cout<<endl;
	
	int a,b,c;	//�� ���� ���� 
	int val=0;	//����,������,�������� �� 
	for(int i=0; i<size; ++i){
		for(int j=0; j<size; ++j){
			for(int k=0; k<size; ++k){
				a = prime[i];
				b = prime[j];
				c = prime[k];
				val = (a*a)+(b*b*b)+(c*c*c*c);
				if(val<n){
					answer++;	//5000�̸��̸� count 
//					cout<<a<<' '<<b<<' '<<c<<' '<<endl; 
				}
			}
		}
	} 
	
	return answer;
	
	
}



int main(void){
	int num = 5000;
	int answer = solution(num);
	cout<< answer << endl;
	
	
	return 0;
}
