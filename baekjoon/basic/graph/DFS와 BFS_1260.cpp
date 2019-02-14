#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

vector<int> v[1001];
bool check[1001];

void DFS(int n){
	check[n] = true;
	printf("%d ", n);
	for(int i=0; i<v[n].size(); ++i){
		int x = v[n][i];
		if( check[x] == false )
			DFS(x);
	}
}

void BFS(int n){
	queue<int> q;
	memset(check, false, sizeof(check));
	q.push(n);
	check[n]=true;
	while(!q.empty()){
		int x = q.front();
		q.pop();
		printf("%d ", x);
		for(int i=0; i<v[x].size(); ++i){
			int y = v[x][i];
			if(check[y]==false){
				check[y]=true;
				q.push(y);
			}
		}
	}

}

void answer(){
	int node, edge, start;
	scanf("%d %d %d", &node, &edge, &start);
	
	int n1, n2;
	for(int i=0; i<edge; ++i){
		scanf("%d %d", &n1, &n2);
		v[n1].push_back(n2);
		v[n2].push_back(n1);
	}
	for(int i=1; i<=node; ++i)
		sort(v[i].begin(), v[i].end());
	
//	for(int i=1; i<=node; ++i){
//		for(int j=0; j<v[i].size(); ++j){
//			cout<<v[i][j]<<' ';
//		}
//		cout<<'\n';
//	}
//	cout<<'\n';

	DFS(start);
	printf("\n");
	BFS(start);
	printf("\n");

}

int main(){
	answer();
	return 0;
}
