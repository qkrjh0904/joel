#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


bool check[26][26] = {false, };
int danji[26][26] = {0, };
int v[26][26] = {0,};
int n=0;
int cnt=0;


void BFS(int i, int j, int d){
	check[i][j] = true;
	danji[i][j] = d;
	cnt++;
	if(j==n && i<n){
		if(v[i][j-1]==1 && check[i][j-1]==false)
			BFS(i, j-1, d);
		if(v[i+1][j]==1 && check[i+1][j]==false)
			BFS(i+1, j, d);
		if(v[i-1][j]==1 && check[i-1][j]==false)
			BFS(i-1, j, d);
	}
	else if(i==n && j<n){
		if(v[i][j+1]==1 && check[i][j+1]==false)
			BFS(i, j+1, d);
		if(v[i][j-1]==1 && check[i][j-1]==false)
			BFS(i, j-1, d);
		if(v[i-1][j]==1 && check[i-1][j]==false)
			BFS(i-1, j, d);
	}
	else if(i==n && j==n){
		if(v[i][j-1]==1 && check[i][j-1]==false)
			BFS(i, j-1, d);
		if(v[i-1][j]==1 && check[i-1][j]==false)
			BFS(i-1, j, d);
	}
	else{
		if(v[i][j+1]==1 && check[i][j+1]==false)
			BFS(i, j+1, d);
		if(v[i][j-1]==1 && check[i][j-1]==false)
			BFS(i, j-1, d);
		if(v[i+1][j]==1 && check[i+1][j]==false)
			BFS(i+1, j, d);
		if(v[i-1][j]==1 && check[i-1][j]==false)
			BFS(i-1, j, d);
	}
}

int main(){
	scanf("%d", &n);

	string s;
	for(int i=1; i<=n; ++i){
		cin>>s;
		for(int j=1; j<=s.size(); ++j){
			v[i][j] = s[j-1]-'0';
		}
	}
	
//	for(int i=1; i<=n; ++i){
//		for(int j=1; j<=n; ++j){
//			cout<<v[i][j]<<' ';
//		}
//		cout<<endl;
//	}
	vector<int> count;
	int d=1;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=n; ++j){
			if(v[i][j]==1 && check[i][j]==false){
				BFS(i, j, d);
				d++;
				count.push_back(cnt);
				cnt=0;
			}
			
		}
	}
	
//	cout<<endl;
//	for(int i=1; i<=n; ++i){
//		for(int j=1; j<=n; ++j){
//			cout<<danji[i][j]<<' ';
//		}
//		cout<<endl;
//	}
//	cout<<endl;
	
	
	sort(count.begin(), count.end());
	
	cout<<d-1<<endl;
	for(int i=0; i<count.size(); ++i)
		cout<<count[i]<<endl;
		
	return 0;
}
