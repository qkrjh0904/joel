#include <iostream>

using namespace std;

long long d[101] = {0, };
long long answer(){
	
	int n;
	cin>>n;
	
	d[1] = d[2] = d[3] = 1;
	d[4] = d[5] = 2;
	
	if( d[n]>0 )
		return d[n];
	
	for(int i=6; i<=n; ++i){
		d[i] = d[i-1]+d[i-5];
	}
	
	
	return d[n];
}

int main(void){
	int T;
	cin>>T;
	for(int i=0; i<T; ++i){
		cout<<answer()<<'\n';
	}
	
	return 0;
} 
