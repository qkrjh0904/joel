#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v[1001];
bool check[1001];
int cnt=0;
void DFS(int n){
	if(check[n]==true)
		return;
	cnt++;
	check[n] = true;
	
	for(int i=0; i<v[n].size(); ++i){
		int x = v[n][i];
		if( check[x] == false ){
			cnt--;
			DFS(x);
		}
	}
}

void answer(){
	int node, edge;
	scanf("%d %d", &node, &edge);
	
	int n1, n2;
	for(int i=0; i<edge; ++i){
		scanf("%d %d", &n1, &n2);
		v[n1].push_back(n2);
		v[n2].push_back(n1);
	}
	for(int i=1; i<=node; ++i)
		sort(v[i].begin(), v[i].end()); 

	for(int i=1; i<=node; ++i)
		DFS(i);
	
	printf("%d\n", cnt);
	

}

int main(){
	answer();
	return 0;
}
