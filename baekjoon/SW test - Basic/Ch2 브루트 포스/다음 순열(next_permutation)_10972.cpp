#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solution(){
	int n;
	cin>>n;
	vector<int> v(n);
	for(int i=0; i<n; ++i)
		cin>>v[i];
	
	if(next_permutation(v.begin(), v.end())==false){
		cout<<-1<<'\n';
		return;
	}
	for(int i=0; i<v.size(); ++i)
		cout<<v[i]<<' ';
	cout<<'\n';	
}
int main(){
	solution();
	return 0;
}
