#include <iostream>

using namespace std;


long long answer(void){
	
	int a[100001] = {0, };
	long long d[100001] = {0, };
	 
	long long answer=0; 
	int n;
	cin>>n;
	
	int num;
	for(int i=1; i<=n; ++i){
		cin>>num;
		a[i] = num;
	}
	
	for(int i=1; i<=n; ++i){
		d[i] = a[i];
		if( d[i] < d[i-1]+a[i] )
			d[i] = d[i-1]+a[i]; 
	}
	
	answer = d[1];
	for(int i=1; i<=n; ++i){
		if(answer < d[i])
			answer = d[i];
	}
	return answer;
	
}

int main(void){

	cout<<answer()<<'\n';
	
	return 0;
}
