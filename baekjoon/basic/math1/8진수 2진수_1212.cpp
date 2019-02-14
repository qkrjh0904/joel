#include <iostream>
#include <string>
#include <vector>

using namespace std;

void answer(){
	string s;
	cin>>s;
	int answer=0;
	int size = s.size();
	
	if(s=="0"){
		cout<<0<<endl;
		return;
	}
	
	int temp=0;
	int n1, n2, n3;
	for(int i=0; i<size; i++){
		temp = s[i]-'0';
		n3 = temp%2;
		temp/=2;
		n2 = temp%2;
		temp/=2;
		n1 = temp;
		
		if(i==0){
			if(n1!=0)
				cout<<n1<<n2<<n3;
			else if(n2!=0)
				cout<<n2<<n3;
			else
				cout<<n3;
		}
		else
			cout<<n1<<n2<<n3;
	}
	
	cout<<'\n';
	
	 
}

int main(void){
	answer();
	return 0;
}
