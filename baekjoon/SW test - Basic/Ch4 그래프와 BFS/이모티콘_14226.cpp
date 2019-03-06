#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <cstring>

using namespace std;

int time[1001][1001];
int main(){
	int n;
	cin>>n;
	memset(time, -1, sizeof(time));
	queue<pair<int, int>> q;
	q.push(make_pair(1, 0));
	time[1][0] = 0;
	while(!q.empty()){
		int s,c;
		tie(s, c) = q.front();
		q.pop();
		//copy
		if(time[s][s]==-1){
			time[s][s] = time[s][c]+1;
			q.push(make_pair(s, s));
		}
		//paste
		if(s+c<=n && time[s+c][c]==-1){
			time[s+c][c] = time[s][c]+1;
			q.push(make_pair(s+c, c));
		}
		//delete
		if(s-1>=0 && time[s-1][c]==-1){
			time[s-1][c] = time[s][c]+1;
			q.push(make_pair(s-1, c));
		}
	}
	int min=-1;
	for(int i=0; i<=1000; ++i){
		if(time[n][i] != -1){
			if(min==-1 || min>time[n][i])
				min = time[n][i];
		}
	}
	cout<<min<<'\n';
		
	
	return 0;
}
