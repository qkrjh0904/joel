#include <iostream>
#include <vector>

using namespace std;

int solution(int n){
    int answer=0;

	vector<int> prime = {2};		//n������ �Ҽ� ����
	for(int i=3; i<n; i+=2){		//Ȧ���� ��� 
		prime.push_back(i);
		for(int j=3; j<i-1; j+=2){	//¦���� Ȧ���� ����� �� �� ����. 
			if(i%j==0){
				prime.pop_back();
				break;
			}
		}
	}
	
	for(int i=0; i<prime.size(); ++i)
		cout<<prime[i]<<' ';
	cout<<endl;
	
	for(int i=0; i<prime.size(); ++i){
		if(prime[i]>10){
			prime
		}
	}


    return answer;
}

int main(void){

	int n = 1000;
	int answer = solution(n);
	cout<< answer <<endl;
	return 0;
} 
