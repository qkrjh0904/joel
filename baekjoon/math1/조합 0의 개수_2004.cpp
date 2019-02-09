#include <iostream>
#include <algorithm>

using namespace std;

void answer(){
	long long n, m, a;
	cin>>n>>m;
	a = n-m;
	
	long long two=0, five=0;

	
	for(long long i=2; i<=n; i*=2){
		two += n/i;
	}
	for(long long i=5; i<=n; i*=5){
		five += n/i;
	}
		
	for(long long i=2; i<=a; i*=2)
		two -= a/i;
	for(long long i=5; i<=a; i*=5)
		five -= a/i;
	
	for(long long i=2; i<=m; i*=2)
		two -= m/i;
	for(long long i=5; i<=m; i*=5)
		five -= m/i;
		
	cout<<min(two, five)<<endl;
	
	
	
}

int main(void){
	answer();
	return 0;
}
