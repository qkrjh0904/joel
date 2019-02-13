#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int v[1000][1000] = {0, };
int date[1000][1000] = {0, };
bool check[1000][1000] = {false, };

int main(){
	int dx[] = {0, 0, 1, -1};
	int dy[] = {1, -1, 0, 0};
	
	int m, n;
	scanf("%d %d", &m, &n);
	for(int i=0; i<n; ++i){
		for(int j=0; j<m; ++j){
			int num;
			scanf("%d", &num);
			v[i][j] = num;
			if(num==-1)
				date[i][j] = -1;
		}
	}

	queue<pair<int, int>> q;
	for(int i=0; i<n; ++i){
		for(int j=0; j<m; ++j){
			if(v[i][j]==1){
				q.push(make_pair(i, j));
				date[i][j] = 1;
				check[i][j] = true;
			}
		}
	}
	
	
	while( !q.empty() ){
		int x = q.front().first;
		int y = q.front().second;
		
		q.pop();
		for(int i=0; i<4; ++i){
			int nx = x+dx[i];
			int ny = y+dy[i];
			if( nx>=0 && nx<n && ny>=0 && ny<m ){
				if( check[nx][ny] == false && v[nx][ny]==0 ){
					q.push(make_pair(nx, ny));
					date[nx][ny] = date[x][y]+1;
					check[nx][ny] = true;
				}
			}
		}
	}
	
//	cout<<endl;
//	for(int i=0; i<n; ++i){
//		for(int j=0; j<m; ++j){
//			cout<<date[i][j]<<' ';
//		}
//		cout<<endl;
//	}
//	cout<<endl;
	
	int max=0;
	for(int i=0; i<n; ++i){
		for(int j=0; j<m; ++j){
			if( date[i][j]==0 ){
				printf("%d\n", -1);
				return 0;
			}
			if( max<date[i][j] )
				max = date[i][j];
		}
	}
	printf("%d\n", max-1);
		
	return 0;
}
