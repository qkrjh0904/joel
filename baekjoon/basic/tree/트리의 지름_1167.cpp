#include <iostream>
#include <vector> 

using namespace std;

vector<pair<int, int>> v[100001];
vector<int> dist(100001);
vector<bool> check(100001);

void DFS(int node){
	check[node] = true;
	for(int i=0; i<v[node].size(); ++i){
		int x = v[node][i].first;
		if( check[x]==false ){
			dist[x] = v[node][i].second + dist[node];
			DFS(x);
		}
	}
}

int main(){
	int n;
	scanf("%d", &n);
	
	for(int i=0; i<n; ++i){
		int p, c, d;
		scanf("%d", &p);
		while(true){
			scanf("%d", &c);
			if(c==-1)
				break;
			scanf("%d", &d);
			v[p].push_back(make_pair(c, d));
		}
	}
	
	int max=0;
	for(int i=1; i<=n; ++i){
		DFS(i);
		
		for(int j=i; j<=n; ++j){
			if(max<dist[j])
				max = dist[j];
		}
//		for(int j=1; j<=n; ++j)
//			printf("%3d ", dist[j]);
//		cout<<endl;
		for(int j=1; j<=n; ++j){
			dist[j] = 0;
			check[j] = false;
		}
	}
	printf("%d\n", max);

	return 0;
}
