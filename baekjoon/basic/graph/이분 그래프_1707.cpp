#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v[20001];
int check[20001];
bool yes_or_no = true;

void DFS(int n, int m){
	check[n] = m;
	for(int i=0; i<v[n].size(); ++i){
		int x = v[n][i];
		if( check[x] == 0 ){
			DFS(x, 3-m);
		}
	}
}

void answer(){
	int t;
	scanf("%d", &t);
	for(int i=0; i<t; ++i){
		int node, edge;
		scanf("%d %d", &node, &edge);
		
		yes_or_no = true;
		for(int i=0; i<=node; ++i){
			check[i]=0;
			v[i].clear();
		}
		
		
		for(int i=0; i<edge; ++i){
			int n1, n2;
			scanf("%d %d", &n1, &n2);
			v[n1].push_back(n2);
			v[n2].push_back(n1);
		}
	
		for(int i=1; i<=node; ++i){
			if(check[i]==0)
				DFS(i, 1);
		}
		
		for(int i=1; i<=node; ++i){
			for(int j=0; j<v[i].size(); ++j){
				int x = v[i][j];
				if(check[i]==check[x])
					yes_or_no = false;
			}
		}
		
		
		
		if( yes_or_no )
			printf("YES\n");
		else
			printf("NO\n");

	}
}

int main(){
	answer();
	return 0;
}
