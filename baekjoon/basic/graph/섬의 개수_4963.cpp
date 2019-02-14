#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


bool check[51][51] = {false, };
int danji[51][51] = {0, };
int v[51][51] = {0,};
int w, h;

void BFS(int i, int j, int d){
	check[i][j] = true;
	danji[i][j] = d;
	
	if(j==w && i<h){
		if(v[i][j-1]==1 && check[i][j-1]==false)
			BFS(i, j-1, d);
		if(v[i+1][j]==1 && check[i+1][j]==false)
			BFS(i+1, j, d);
		if(v[i-1][j]==1 && check[i-1][j]==false)
			BFS(i-1, j, d);
		if(v[i-1][j-1]==1 && check[i-1][j-1]==false)
			BFS(i-1, j-1, d);
		if(v[i+1][j-1]==1 && check[i+1][j-1]==false)
			BFS(i+1, j-1, d);
	}
	else if(i==h && j<w){
		if(v[i][j+1]==1 && check[i][j+1]==false)
			BFS(i, j+1, d);
		if(v[i][j-1]==1 && check[i][j-1]==false)
			BFS(i, j-1, d);
		if(v[i-1][j]==1 && check[i-1][j]==false)
			BFS(i-1, j, d);
		if(v[i-1][j-1]==1 && check[i-1][j-1]==false)
			BFS(i-1, j-1, d);
		if(v[i-1][j+1]==1 && check[i-1][j+1]==false)
			BFS(i-1, j+1, d);
	}
	else if(i==h && j==w){
		if(v[i][j-1]==1 && check[i][j-1]==false)
			BFS(i, j-1, d);
		if(v[i-1][j]==1 && check[i-1][j]==false)
			BFS(i-1, j, d);
		if(v[i-1][j-1]==1 && check[i-1][j-1]==false)
			BFS(i-1, j-1, d);
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
			
		if(v[i+1][j+1]==1 && check[i+1][j+1]==false)
			BFS(i+1, j+1, d);
		if(v[i-1][j-1]==1 && check[i-1][j-1]==false)
			BFS(i-1, j-1, d);
			
		if(v[i+1][j-1]==1 && check[i+1][j-1]==false)
			BFS(i+1, j-1, d);
		if(v[i-1][j+1]==1 && check[i-1][j+1]==false)
			BFS(i-1, j+1, d);
	}
}

int main(){
	while(true){
		
		scanf("%d %d", &w, &h);	
		
		if(w==0 && h==0)
			break;
		 
		int n;
		for(int i=1; i<=h; ++i){
			for(int j=1; j<=w; ++j){
				scanf("%d", &n);
				v[i][j] = n;
			}
		}
		
//		for(int i=1; i<=h; ++i){
//			for(int j=1; j<=w; ++j){
//				cout<<v[i][j]<<' ';
//			}
//		cout<<endl;
//		}
		
		int d=1;
		for(int i=1; i<=h; ++i){
			for(int j=1; j<=w; ++j){
				if(v[i][j]==1 && check[i][j]==false){
					BFS(i, j, d);
					d++;
				}
			}
		}
		
		cout<<d-1<<endl;
//		cout<<endl;
//		for(int i=1; i<=h; ++i){
//			for(int j=1; j<=w; ++j){
//				cout<<danji[i][j]<<' ';
//			}
//			cout<<endl;
//		}
//		cout<<endl;
		
		
		
		for(int i=1; i<=h; ++i){
			for(int j=1; j<=w; ++j){
				v[i][j]=0;
				danji[i][j]=0;
				check[i][j]=0;
			}
		}
		
	}
		
	return 0;
}
