#include <iostream>
#include <stack>
#include <string>

using namespace std; 

int main(void){
	
	string s;
	stack<string> st;
	int index = 0;
	int answer = 0;
	
	cin>>s;
	for(int i=0; i<s.size(); ++i){
		if(s[i]=='('){
			st.push("(");
			index=1;
		}
		else{
			if(index==1){
				st.pop();
				answer += st.size();
			}
			else{
				st.pop();
				answer++;
			}
			index=0;
		}
	}
	cout<<answer<<endl;
	
	return 0;
}
