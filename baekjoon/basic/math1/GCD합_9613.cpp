#include <iostream>

using namespace std;

int gcd(int a, int b){
	if( b==0 )
		return a;
	return gcd(b, a%b);
}

long long answer(){
	int n;
	cin>>n;
	
	long long answer=0;
	
	int num[101];
	int input;
	for(int i=1; i<=n; ++i){
		cin>>input;
		num[i] = input;
	}
	
	for(int i=1; i<=n-1; ++i)
		for(int j=i+1; j<=n; ++j)
			answer += gcd(num[i], num[j]);
	
	
	return answer;
}

int main(void){
	int T;
	cin>>T;
	
	for(int i=0; i<T; ++i)
		cout<<answer()<<'\n';

	return 0;
}
