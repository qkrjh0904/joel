#include <iostream>

using namespace std;

long long memo[91] = {0, };
long long answer(int n){
	if(n<=2)
		return 1;
	
	if(memo[n]>0)
		return memo[n];
	
	memo[n] = answer(n-1)+answer(n-2);
	
	return memo[n];
	
}

int main(void){
	int n;
	cin>>n;
	
	cout<<answer(n)<<'\n';
	return 0;
}
