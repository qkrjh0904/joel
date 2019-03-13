#include <iostream>

using namespace std;

int memo[11];
int go(int n){
	if(n<=2)
		return n;
	if(n==3)
		return 4;
	if(memo[n]>0)
		return memo[n]; 
	
	memo[n] = go(n-1)+go(n-2)+go(n-3);
	return memo[n];
}

void solution(){
	int t;
	cin>>t;
	
	for(int i=0; i<t; ++i){
		int n;
		cin>>n;
		cout<<go(n)<<'\n';
	}
}
int main(){
	solution();
	return 0;
}
