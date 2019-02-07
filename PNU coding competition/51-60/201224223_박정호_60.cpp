#include <iostream>
#include <vector>

using namespace std;

int solution(int num){
	int answer = 0;
	int n = num;	//num미만의 숫자. 
	//제곱+세제곱+네제곱 에서 가능한 가장 큰 소수는 67이다.	
	vector<int> prime = {2};		//67이하의 소수 벡터
	for(int i=3; i<=67; i+=2){		//홀수만 고려 
		prime.push_back(i);
		for(int j=3; j<i-1; j+=2){	//짝수는 홀수의 약수가 될 수 없으므로 j+=2. 
			if(i%j==0){
				prime.pop_back();
				break;
			}
		}
	}
	int size = prime.size();
	//소수 출력. 
//	for(int i=0; i<size; ++i)
//		cout<<prime[i]<<' ';
//	cout<<endl;
	
	int a,b,c;	//각 항의 지수 
	int val=0;	//제곱,세제곱,네제곱의 합 
	for(int i=0; i<size; ++i){
		for(int j=0; j<size; ++j){
			for(int k=0; k<size; ++k){
				a = prime[i];
				b = prime[j];
				c = prime[k];
				val = (a*a)+(b*b*b)+(c*c*c*c);
				if(val<n){
					answer++;	//5000미만이면 count 
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
