#include <iostream>
#include <string>

using namespace std;

string solution(string s)
{
	for(int i=0; i<s.size(); ++i){
		if(s[i]>=65 && s[i]<=90){
			s[i] += 13;
			if(s[i]>90)
				s[i] -= 26;
		}
		else if(s[i]>=97 && s[i]<=122){
			//아스키코드값이 127까지만 있기때문에, 대문자방법처럼하면 오류날 수 있음. 
			if(s[i]<110)
				s[i] += 13;
			else
				s[i] -= 13;
		}
	}
	return s;
}

int main(void)
{
	
	string s;
	getline(cin, s);
	
	string answer = solution(s);
	cout<<answer<<endl;

	return 0;
}
