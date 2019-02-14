#include <iostream>

using namespace std;

bool isPrime(int n){
	if( n<2 )
		return false;
	else{
		for(int i=2; i*i<=n; ++i){
			if( n%i==0 )
				return false;
		}
	}
	return true;
}

int answer(int n){
	int num;
	int answer=0;
	for(int i=0; i<n; ++i){
		cin>>num;
		if( isPrime(num) ){
			answer++;
		}
			
	}
	return answer;
}

int main(void){
	int n;
	cin>>n;
	cout<<answer(n)<<'\n';
	
	return 0;
}
