#include <iostream>
#include <vector> 
#include <queue>
using namespace std;

int n, m;
int map[8][8];
int temp[8][8];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
vector<int> safe;

void bfs(){
	queue<pair<int, int>> q;
	for(int i=0; i<n; ++i){
		for(int j=0; j<m; ++j){
			temp[i][j] = map[i][j];
			if(temp[i][j]==2)
				q.push(make_pair(i, j));
		}
	}
	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for(int i=0; i<4; ++i){
			int nx = x+dx[i];
			int ny = y+dy[i];
			if(nx>=0 && nx<n && ny>=0 && ny<m){
				if(temp[nx][ny]==0){
					temp[nx][ny] = 2;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
	
	int cnt=0;
	for(int i=0; i<n; ++i){
		for(int j=0; j<m; ++j){
			if(temp[i][j]==0)
				cnt++;
		}
	}
	safe.push_back(cnt);
} 
void solution(){
	cin>>n>>m;
	for(int i=0; i<n; ++i){
		for(int j=0; j<m; ++j){
			cin>>map[i][j];
		}
	}
	
	for(int x1=0; x1<n; ++x1){
		for(int y1=0; y1<m; ++y1){
			if(map[x1][y1]!=0) continue;
			for(int x2=0; x2<n; ++x2){
				for(int y2=0; y2<m; ++y2){
					if(map[x2][y2]!=0) continue;
					for(int x3=0; x3<n; ++x3){
						for(int y3=0; y3<m; ++y3){
							if(map[x3][y3]!=0) continue;
							if(x1 == x2 && y1 == y2) continue;
							if(x2 == x3 && y2 == y3) continue;
							if(x3 == x1 && y3 == y1) continue;
							map[x1][y1] = 1;
							map[x2][y2] = 1;
							map[x3][y3] = 1;
							
							bfs();
							
							map[x1][y1] = 0;
							map[x2][y2] = 0;
							map[x3][y3] = 0;
							
						}
					}
				}
			}
		}
	}
	
	int answer=0;
	for(int x : safe){
		if( answer < x )
			answer = x;
	}
	cout<<answer<<'\n';
	
	
	
	
}

int main(){
	solution();
	return 0;
}
