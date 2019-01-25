#include <iostream>
#include <cmath>

using namespace std;

int answer(int n){
	
	int d[100001] = {0, };
	
	for(int i=1; i<=n; ++i){
		d[i] = i;
		for(int j=1; j*j<=i; ++j){
			if( d[i] > d[i-j*j]+1 )
				d[i] = d[i-j*j]+1;
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
