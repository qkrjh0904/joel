#include <iostream>

using namespace std;

long long answer(void){
	
	int a[301] = {0, };
	long long d[301] = {0, };
	 
	long long answer=0; 
	int n;
	cin>>n;
	
	int num;
	for(int i=1; i<=n; ++i){
		cin>>num;
		a[i] = num;
	}


	d[1] = a[1];
	d[2] = a[1]+a[2];
	for(int i=3; i<=n; ++i){
		//i-2번째 계단은 무조건 밟았어야함 
		//i-2번째 계단은 밟으면 안됨, i-3번째 계단은 무조건 밟았어야함 
		d[i] = max( d[i-2]+a[i], d[i-3]+a[i]+a[i-1] ); 
	}

	answer = d[n];
		
	return answer;
}

int main(void){

	cout<<answer()<<'\n';
	
	return 0;
} 
