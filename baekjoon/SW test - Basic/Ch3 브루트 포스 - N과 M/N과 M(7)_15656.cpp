#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> a(10);
vector<bool> check(10);
vector<int> num;

void go(int index, int n, int m){
	if( index==m ){
		for(int i=0; i<m; ++i)
			cout<<a[i]<<' ';
		cout<<'\n';
		return;
	}
	for(int i=0; i<n; ++i){
		a[index] = num[i];
		go(index+1, n, m);
	}
}
int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	
	for(int i=0; i<n; ++i){
		int x;
		scanf("%d", &x);
		num.push_back(x);
	}
	sort(num.begin(), num.end());
	
	go(0, n, m);
	
	return 0;
}
