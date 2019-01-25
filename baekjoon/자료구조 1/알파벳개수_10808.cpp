#include <iostream>
#include <string>

using namespace std; 

int main(void)
{
	string s;
	cin>>s;
	int alpha_num[26] = {0, };
	int n;
	for(int i=0; i<s.size(); ++i){
		n = s[i]-97;
		alpha_num[n]++;
	} 
	
	for(int i=0; i<26; ++i){
		cout<<alpha_num[i]<<' ';
	}
	cout<<endl;
	
	return 0;
}
