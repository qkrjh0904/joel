#include <iostream>
#include <vector>

using namespace std;


vector<int> a(10);

void go(int index, int n, int m){
	vector<bool> check(10);
	if(index==m){
		for(int i=0; i<m; ++i)
			cout<<a[i]<<' ';
		cout<<'\n';
		return;
	}
	for(int i=1; i<=n; ++i){
		if(check[i]) continue;
		check[i] = true;
		a[index] = i;
		go(index+1, n, m);
	}
}
int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	
	go(0, n, m);
	
	return 0;
}
