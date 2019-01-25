#include <iostream>

using namespace std;

int memo[1001];
int answer(int n){
	if(n<=2)
		return n;
	if(memo[n] > 0)
		return memo[n];
	
	memo[n] = (answer(n-1)+answer(n-2))%10007;
	return memo[n];

	
}

int main(void){
	
	int n;
	cin>>n;
	
	cout<<answer(n)<<endl;
	
	return 0;
}
