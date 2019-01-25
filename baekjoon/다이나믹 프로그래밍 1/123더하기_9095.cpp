#include <iostream>

using namespace std;

int memo[12] = {0, };
int answer(int n){
	if(n<=2)
		return n;
	
	if(n==3)
		return 4;
	
	if(memo[n] > 0)
		return memo[n];
	
	memo[n] = answer(n-1)+answer(n-2)+answer(n-3);
	return memo[n]; 
}

int main(void){
	int n;
	cin>>n;
	
	int m;
	for(int i=0; i<n; ++i){
		cin>>m;
		cout<<answer(m)<<'\n';
	}	
	
	
}
