#include <iostream>

using namespace std;

long long answer(void){
	
	int a[301] = {0, };
	long long d[301][3] = {0, };
	 
	long long answer=0; 
	int n;
	cin>>n;
	
	int num;
	for(int i=1; i<=n; ++i){
		cin>>num;
		a[i] = num;
	}


	d[1][1] = a[1];
	for(int i=2; i<=n; ++i){
		//i-2번째 계단은 무조건 밟았어야함 
		d[i][1] = max( d[i-2][2], d[i-2][1] ) + a[i];	
		//i-2번째 계단은 밟으면 안됨, i-3번째 계단은 무조건 밟았어야함 
		d[i][2] = d[i-1][1] + a[i];
	}

	answer = d[n][1];
	if( answer < d[n][2] )
		answer = d[n][2];
		
	return answer;
}

int main(void){

	cout<<answer()<<'\n';
	
	return 0;
} 
