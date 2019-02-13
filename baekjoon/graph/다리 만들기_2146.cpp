#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int v[100][100] = {0, };
int land[100][100] = {0, };
int dist[100][100] = {0, };
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int main(){
	int n;
	scanf("%d", &n);
	for(int i=0; i<n; ++i){
		for(int j=0; j<n; ++j){
			scanf("%d", &v[i][j]);
		}
	}
	
	int cnt=0;
	for(int i=0; i<n; ++i){
		for(int j=0; j<n; ++j){
			if( v[i][j]==1 && land[i][j]==0 ){
				land[i][j] = ++cnt;
				queue<pair<int, int>> q;
				q.push(make_pair(i, j));
				while( !q.empty() ){
					int x = q.front().first;
					int y = q.front().second;
					q.pop();
					for(int k=0; k<4; ++k){
						int nx = x+dx[k];
						int ny = y+dy[k];
						if( nx>=0 && nx<n && ny>=0 && ny<n ){
							if( v[nx][ny] == 1 && land[nx][ny]==0 ){
								land[nx][ny] = cnt;
								q.push(make_pair(nx, ny));
							}
						}
					}
				}
			}
		}
	}
//	cout<<endl;
//	for(int i=0; i<n; ++i){
//		for(int j=0; j<n; ++j){
//			cout<<land[i][j]<<' ';
//		}
//		cout<<endl;
//	}
//	cout<<endl;
	
	queue<pair<int, int>> q;
	for(int i=0; i<n; ++i){
		for(int j=0; j<n; ++j){
			dist[i][j] = -1;
			if(v[i][j]==1){
				q.push(make_pair(i, j));
				dist[i][j]=0;
			}
		}
	}
	
	while( !q.empty() ){
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for(int k=0; k<4; ++k){
			int nx = x+dx[k];
			int ny = y+dy[k];
			if( nx>=0 && nx<n && ny>=0 && ny<n ){
				if( dist[nx][ny]==-1 ){
					dist[nx][ny] = dist[x][y]+1;
					land[nx][ny] = land[x][y];
					q.push(make_pair(nx, ny));
				}
			}
		}
		
	}
//	cout<<endl;
//	for(int i=0; i<n; ++i){
//		for(int j=0; j<n; ++j){
//			cout<<land[i][j]<<' ';
//		}
//		cout<<endl;
//	}
//	cout<<endl;
	
	int ans=-1;
	for(int i=0; i<n; ++i){
		for(int j=0; j<n; ++j){
			for(int k=0; k<4; ++k){
				int x = i+dx[k];
				int y = j+dy[k];
				if( x>=0 && x<n && y>=0 && y<n ){
					if( land[x][y] != land[i][j] ){
						if( ans==-1 || ans>dist[i][j]+dist[x][y]){
							ans = dist[i][j]+dist[x][y];
						}
					}
				}
			}
		}
	}
	printf("%d\n", ans);
	
	return 0;
}
