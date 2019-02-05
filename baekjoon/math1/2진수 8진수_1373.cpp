#include <iostream>
#include <string>
#include <vector>

using namespace std;

void answer(){
	string s;
	cin>>s;
	int answer=0;
	int size = s.size();
	
	if(size%3==1){
		cout<<(s[0]-'0');
	}
	else if(size%3==2){
		cout<< (s[0]-'0')*2 + (s[1]-'0');
	}
	for(int i=size%3; i<size; i+=3){
		cout<<(s[i]-'0')*4 + (s[i+1]-'0')*2 + (s[i+2]-'0');
	}
	
	cout<<endl;
	
	 
}

int main(void){
	answer();
	return 0;
}
