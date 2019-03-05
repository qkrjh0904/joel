#include <iostream>
#include <vector>

using namespace std;

vector<bool> check(10);
vector<int> a(10);

void go(int index, int start, int n, int m){
	if(index==m){
		for(int i=0; i<m; ++i)
			cout<<a[i]<<' ';
		cout<<'\n';
		return;
	}
	for(int i=start; i<=n; ++i){
		if(check[i]) continue;
		check[i] = true;
		a[index] = i;
		go(index+1, i+1, n, m);
		check[i] = false;
	}
}
int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	
	go(0, 1, n, m);
	
	return 0;
}
