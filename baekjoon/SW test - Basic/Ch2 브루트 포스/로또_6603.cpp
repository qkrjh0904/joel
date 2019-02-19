#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	
	while( true ){ 
		int n;
		scanf("%d", &n); 
		if( n==0 )
			break;
		
		vector<int> v(n);
		vector<int> p(n);
		
		for(int i=0; i<n; ++i)
			scanf("%d", &v[i]);
		for(int i=6; i<p.size(); ++i)
				p[i] = 1;
		do{
			for(int i=0; i<n; ++i){
				if( p[i]==0 )
					printf("%d ", v[i]);
			}
			printf("\n");
		}while(next_permutation(p.begin(), p.end()));
		printf("\n");
	}
	
	
	return 0;
}
