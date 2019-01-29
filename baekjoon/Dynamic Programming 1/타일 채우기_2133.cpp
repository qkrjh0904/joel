#include <iostream>

using namespace std;

int d[31] = {0, };
int answer(int n){
	if( n%2 == 1 )
		return 0;
	
	d[0] = 1;
	for(int i=2; i<=n; i+=2){
		d[i] = 3*d[i-2];
		for(int j=4; i-j>=0; j+=2){
			d[i] += 2*d[i-j];
		}
	}
	
	
	return d[n];
}

int main(void){
	int n;
	cin>>n;
	cout<<answer(n)<<'\n';
	
	return 0;
} 
