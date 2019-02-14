#include <iostream>

using namespace std;

int gcd(int a, int b){
	if( b==0 )
		return a;
	return gcd(b, a%b);
}

int lcm(int a, int b){
	int g = gcd(a, b);
	
	/*
	A=a*g, B=b*g
	GCD = g
	LCM = abg = (A/g)(B/g)g = AB/g
	*/
	return a*b/g;
}

int answer(){
	int a, b;
	cin>>a>>b;
	cout<< lcm(a,b) << '\n';
}

int main(void){
	int T;
	cin>>T;
	
	for(int i=0; i<T; ++i)
		answer();

	return 0;
}
