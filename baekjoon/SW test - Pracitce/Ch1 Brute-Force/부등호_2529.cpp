#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool check(vector<char> &v, vector<int> &ans){
	for(int i=0; i<v.size(); ++i){
		if(v[i]=='>' && ans[i]<ans[i+1])
			return false;
		if(v[i]=='<' && ans[i]>ans[i+1])
			return false;
	}
	return true;
}

void solution(){
	int n;
	cin>>n;
	
	vector<char> v(n);
	for(int i=0; i<n; ++i){
		cin>>v[i];
	}
	
	vector<int> min_ans(n+1);
	vector<int> max_ans(n+1);
	for(int i=0; i<=n; ++i){
		min_ans[i] = i;
		max_ans[i] = 9-i;
	}
	
	do{
		if(check(v, min_ans))
			break;
	}while(next_permutation(min_ans.begin(), min_ans.end()));
	do{
		if(check(v, max_ans))
			break;
	}while(prev_permutation(max_ans.begin(), max_ans.end()));
	
	for(int i=0; i<max_ans.size(); ++i){
		cout<<max_ans[i];
	}
	cout<<'\n';
	for(int i=0; i<min_ans.size(); ++i){
		cout<<min_ans[i];
	}
	
	
}

int main(){
	solution();
	return 0;
}
