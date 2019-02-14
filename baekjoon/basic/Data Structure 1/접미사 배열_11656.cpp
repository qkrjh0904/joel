#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	
	string s;
	vector<string> v;
	cin>>s;
	
	string temp;
	for(int i=0; i<s.size(); ++i){
		for(int j=i; j<s.size(); ++j){
			temp += s[j];
		}
		v.push_back(temp);
		temp = "";
	}

	sort(v.begin(), v.end());
	for(int i=0; i<v.size(); ++i){
		cout<<v[i]<<endl;
	}
	return 0;
}
