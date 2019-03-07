#include <iostream>
#include <queue>
#include <tuple>

using namespace std;



int main(){
	int r, c;
	cin>>c>>r;
	
	int a[r][c];
	int dist[r][c];
	
	int dx[] = {1, -1, 0, 0};
	int dy[] = {0, 0, 1, -1};
	
	for(int i=0; i<r; ++i){
		for(int j=0; j<c; ++j){
			scanf("%1d", &a[i][j]);
			dist[i][j] = -1;
		}
	}
	
	queue<pair<int, int>> q;
	queue<pair<int, int>> next_q;
	q.push(make_pair(0, 0));
	dist[0][0] = 0;
	
	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for(int i=0; i<4; ++i){
			int nx = x+dx[i];
			int ny = y+dy[i];
			if(nx>=0 && nx<r && ny>=0 && ny<c){
				if(dist[nx][ny]==-1){
					if(a[nx][ny]==0){
						dist[nx][ny] = dist[x][y];
						q.push(make_pair(nx, ny));
					}
					else{
						dist[nx][ny] = dist[x][y]+1;
						next_q.push(make_pair(nx, ny));
					}
				}
			}
		}
		if(q.empty()){
			q = next_q;
			next_q = queue<pair<int, int>>();
		}
	
	}
	
	cout<<dist[r-1][c-1]<<'\n';
	

	

	return 0;
}
