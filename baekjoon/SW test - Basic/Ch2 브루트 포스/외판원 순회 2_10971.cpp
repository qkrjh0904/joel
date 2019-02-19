#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	
	int n;
	scanf("%d", &n); 
	int w[n][n];
	for(int i=0; i<n; ++i){
		for(int j=0; j<n; ++j){
			scanf("%d", &w[i][j]);
		}
	}
	vector<int> v(n);
	for(int i=0; i<n; ++i)
		v[i] = i;

	int ans=10000000;
	do{
		bool ok=true;
		int sum=0;
		int x;
		for(int i=0; i<n-1; ++i){
			x = w[v[i]][v[i+1]];
			if( x==0 ) {ok = false;	break; }
			else sum+= x;
		}
		if( ok && w[v[n-1]][v[0]]!=0 ){
			sum += w[v[n-1]][v[0]];
			ans = min(ans, sum);
		}
	}while(next_permutation(v.begin()+1, v.end()));
	printf("%d\n", ans);
	
	
	return 0;
}
