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
			//�ƽ�Ű�ڵ尪�� 127������ �ֱ⶧����, �빮�ڹ��ó���ϸ� ������ �� ����. 
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
