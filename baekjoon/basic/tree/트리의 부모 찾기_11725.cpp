#include <iostream>
#include <vector> 

using namespace std;

vector<int> v[100001];
vector<int> p(100001);
vector<bool> check(100001);
void DFS(int node){
	check[node] = true;
	for(int i=0; i<v[node].size(); ++i){
		int x = v[node][i];
		if( check[x]==false ){
			p[x] = node;
			DFS(x);
		}
	}
	
}
int main(){
	int n;
	scanf("%d", &n);
	
	for(int i=1; i<n; ++i){
		int n1, n2;
		cin>>n1>>n2;
		v[n1].push_back(n2);
		v[n2].push_back(n1);	
	}
	DFS(1);
	for(int i=2; i<=n; ++i){
		printf("%d\n", p[i]);
	}
	

	return 0;
}
