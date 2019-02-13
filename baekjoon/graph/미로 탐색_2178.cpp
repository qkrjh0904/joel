#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main(){
	int v[100][100] = {0, };
	int dist[100][100] = {0, };
	bool check[100][100] = {false, };
	
	int dx[] = {0, 0, 1, -1};
	int dy[] = {1, -1, 0, 0};
	
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i=0; i<n; ++i){
		for(int j=0; j<m; ++j){
			scanf("%1d", &v[i][j]);
		}
	}

	queue<pair<int, int>> q;
	q.push(make_pair(0, 0));
	
	dist[0][0] = 1;
	check[0][0] = true;
	while( !q.empty() ){
		int x = q.front().first;
		int y = q.front().second;
		
		q.pop();
		for(int i=0; i<4; ++i){
			int nx = x+dx[i];
			int ny = y+dy[i];
			if( nx>=0 && nx<n && ny>=0 && ny<m ){
				if( check[nx][ny] == false && v[nx][ny]==1 ){
					q.push(make_pair(nx, ny));
					dist[nx][ny] = dist[x][y]+1;
					check[nx][ny] = true;
				}
			}
		}
	}
	printf("%d\n", dist[n-1][m-1]);

		
	return 0;
}
