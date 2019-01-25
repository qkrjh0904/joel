#include <iostream>
#include <string>

using namespace std; 

int main(void)
{
	string s;
	cin>>s;
	int alpha_num[26];
	for(int i=0; i<26; ++i){
		alpha_num[i]=-1;
	}
	
	int n=0;
	int cnt=0;
	for(int i=0; i<s.size(); ++i){
		n = s[i]-97;
		if(alpha_num[n] == -1)
			alpha_num[n] = cnt;
		cnt++;
	} 
	
	for(int i=0; i<26; ++i){
		cout<<alpha_num[i]<<' ';
	}
	cout<<endl;
	
	return 0;
}
