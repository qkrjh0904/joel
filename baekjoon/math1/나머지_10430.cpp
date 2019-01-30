#include <iostream>

using namespace std;

int answer(){
	int a, b, c;
	cin>>a>>b>>c;
	
	int n1, n2;
	long long m1, m2;
	n1 = (a+b)%c;
	n2 = (a%c + b%c)%c;
	
	m1 = (a*b)%c;
	m2 = (a%c * b%c)%c;
	
	cout<<n1<<'\n';
	cout<<n2<<'\n'; 
	cout<<m1<<'\n'; 
	cout<<m2<<'\n';

}

int main(void){
	
	answer();

	return 0;
}
