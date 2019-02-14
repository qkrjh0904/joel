#include <iostream>

using namespace std;

int answer(int n){
	if(n<=1)
		return 1;
	return n*answer(n-1);
	
	
	
}

int main(void){
	int n;
	cin>>n;
	cout<<answer(n)<<'\n';
	return 0;
}
