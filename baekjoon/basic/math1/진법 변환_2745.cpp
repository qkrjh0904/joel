#include <iostream>
#include <string>
#include <vector>

using namespace std;

void answer(){
	string s;
	int a;
	long long num=0;
	
	cin>>s>>a;
	long long temp=1;
	for(int i=s.size()-1; i>=0; --i){
		if( s[i]>='A' && s[i]<='Z' ){
			num += (s[i]-55)*temp;
		}
		else{
			num += (s[i]-48)*temp;
		}
		temp *= a;
	}
	
	cout<<num<<'\n';
	 
}

int main(void){
	answer();
	return 0;
}
