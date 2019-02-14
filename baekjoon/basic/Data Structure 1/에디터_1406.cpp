#include <iostream>
#include <stack>
#include <string>

using namespace std; 

int main(void){
	
	string s;
	int n;
	stack<char> left;
	stack<char> right;
	char c, x;
	
	
	cin>>s>>n;
	for(int i=0; i<s.size(); ++i)
		left.push(s[i]);
	
	for(int i=0; i<n; ++i){
		cin>>c;
		if(c == 'L'){
			if(left.empty())
				continue;
			right.push(left.top());
			left.pop();
		}
		else if(c == 'D'){
			if(right.empty())
				continue;
			left.push(right.top());
			right.pop();
		}
		else if(c == 'B'){
			if(left.empty())
				continue;
			left.pop();
		}
		else if(c == 'P'){
			cin>>x;
			left.push(x);
		}
	}
	
	while(!left.empty()){
		right.push(left.top());
		left.pop();
	}
	while(!right.empty()){
		cout<<right.top();
		right.pop();
	}
	
	return 0;
}
