#include <iostream>

using namespace std;

int memo[1000001];
int answer(int n){
	if(n==1)
		return 0;
	if(memo[n]>0)
		return memo[n];
	
	memo[n] = answer(n-1)+1;
	if(n%2==0){
		int temp = answer(n/2) + 1;
		if(memo[n] > temp)
			memo[n] = temp;
	}
	if(n%3==0){
		int temp = answer(n/3) +1;
		if(memo[n] > temp)
			memo[n] = temp;
	}
	return memo[n];
	
}

int main(void){
	
	int n;
	cin>>n;
	
	cout<<answer(n)<<endl;
	
	return 0;
}
