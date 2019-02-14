#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void answer(){
	int n;
	int x, y;
	cin>> n;
	
	vector< pair<int, int> > v(n);
	for(int i=0; i<n; ++i){
		cin>> x >> y ;
		v[i].first = y;
		v[i].second = x;
	}
	
	sort( v.begin(), v.end());
	for(int i=0; i<n; ++i)
		cout<<v[i].second<<' '<<v[i].first<<'\n';
} 

int main(){
	answer();
	return 0;
}
