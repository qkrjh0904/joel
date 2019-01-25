#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	
	string new_ab = a+b;
	string new_cd = c+d;
	
	long long ab = stoll(new_ab);
	long long cd = stoll(new_cd);
	
	long long answer = ab+cd;
	cout<< answer << endl;
	

	return 0;
}
