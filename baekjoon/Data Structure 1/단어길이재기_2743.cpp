#include <iostream>
#include <string>

using namespace std;

int solution(string s)
{
	int len=0;
	for(int i=0; s[i]; ++i)
		len++;
	
	return len;
}

int main(void)
{
	string s;
	cin>>s;
	
	int answer = solution(s);
	cout<<answer<<endl;
	
	
	return 0;
}
