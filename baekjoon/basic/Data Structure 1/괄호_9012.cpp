#include <iostream>
#include <stack>
#include <string>

using namespace std; 

int main(void){
	
	int n;
	cin>>n;
	
	
	
	while(n>0){
		n--;
		
		int flag=0;
		string s;
		stack<string> st;
	
		cin>>s;
		for(int i=0; i<s.size(); ++i){
			if(s[i] == '(')
				st.push("(");
			else{
				if(st.empty()){
					cout<<"NO"<<endl;
					flag=1;
					break;
				}
				st.pop();
			}
		}
			
		if(flag==0){
			if(st.empty())
				cout<<"YES"<<endl;	
			else
				cout<<"NO"<<endl;
		}
		
	}
	
	return 0;
}
