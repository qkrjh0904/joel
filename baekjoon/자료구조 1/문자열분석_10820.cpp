#include <iostream>
#include <string>

using namespace std;

void answer(string s){
	int cnt[4] = {0, };
	
	for(int i=0; i<s.size(); ++i){
		if(s[i]==32)
			cnt[3]++;
		else if(s[i] >= 65 && s[i] <= 90)
			cnt[1]++;
		else if(s[i] >= 97 && s[i] <= 122)
			cnt[0]++;
		else if(s[i] >= 48 && s[i] <= 57)
			cnt[2]++;
	}
	
	for(int i=0; i<4; ++i)
		cout<<cnt[i]<<' ';
	cout<<endl;
}

int main(void)
{
	while(1){
		string s="";
		getline(cin, s);
		
		if(s.size() == 0)
			break;
		answer(s);	
	}
	
	
	

	
	
	return 0;
}
