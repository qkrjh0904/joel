#include <iostream>

using namespace std;

long long memo[101][10] = {0,};
long long answer(int n){
	for(int i=1; i<=9; ++i)
		memo[1][i] = 1;

	for(int i=2; i<=n; ++i){
		for(int j=0; j<=9; ++j){
			if(j-1>=0)
				memo[i][j] += memo[i-1][j-1];
			if(j+1<=9)
				memo[i][j] += memo[i-1][j+1];
			memo[i][j] %= 1000000000;
		}
	}
	
	long long answer=0;
	for(int i=0; i<=9; ++i){
		answer += memo[n][i];
		answer %= 1000000000;
	}
	
	return answer%1000000000;
	
}

int main(void){
	int n;
	cin>>n;
	
	cout<<answer(n)<<'\n';
	return 0;
}
