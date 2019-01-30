#include <iostream>
#include <string>
#include <vector>

using namespace std;

void answer(){
	long long num;
	int a;
	cin>>num>>a;
	
	long long q = 1;
	long long r;
	vector<string> s;
	string temp="";
	while( q!=0 ){
		q = num/a;
		r = num%a;
		num /= a;
		
		if( r>=10 ){
			temp = r+55;
			s.push_back(temp);
		}
		else{
			temp = r+48;
			s.push_back(temp);
		}
	}
	
	for(int i=s.size()-1; i>=0; --i){
		cout<<s[i];
	}
	cout<<'\n';
}

int main(void){
	answer();
	return 0;
}
