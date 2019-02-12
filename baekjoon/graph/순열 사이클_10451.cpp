#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v(1001);
vector<bool> check(1001);
int cnt=0;

void DFS(int n){
	check[n] = true;
	
	int x = v[n];
	if( check[x]==false )
		DFS(x);
	else
		cnt++;
}

void answer(){
	int t;
	scanf("%d", &t);
	for(int i=0; i<t; ++i){
		int leng;
		scanf("%d", &leng); 
		int n;
		for(int i=1; i<=leng; ++i){
			scanf("%d", &n);
			v[i] = n;
		}
	
		for(int i=1; i<=leng; ++i){
			if(check[i]==false)
				DFS(i);
		}
		printf("%d\n", cnt);
		cnt=0;
		for(int i=1; i<=leng; ++i){
			v[i]=0;
			check[i]=false;
		}
	}
}

int main(){
	answer();
	return 0;
}
