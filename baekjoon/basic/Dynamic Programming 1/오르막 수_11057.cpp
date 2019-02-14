#include <iostream>

using namespace std;

long long memo[1001][10] = {0, }; 
long long answer(int n){
	for(int i=0; i<=9; ++i)
		memo[1][i] = 1;
		
	for(int i=2; i<=n; ++i){
		for(int j=0; j<=9; ++j){
			for(int k=0; k<=j; ++k){
				memo[i][j] += memo[i-1][k];
				memo[i][j] %= 10007;
			}
		}
	}
	
	long long answer=0;
	for(int i=0; i<=9; ++i){
		answer += memo[n][i];
		answer %= 10007;
	}
	
	return answer%10007;
	
}

int main(void){
	int n;
	cin>>n;
	
	cout<<answer(n)<<'\n';
	return 0;
}
