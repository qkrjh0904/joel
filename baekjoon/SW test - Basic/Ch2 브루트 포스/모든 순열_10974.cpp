#include <iostream>

using namespace std;

bool next_permutation(int *v, int n){
	int i=n-1;
	while( i>0 && v[i-1]>v[i] )
		i-=1;
	
	if( i==0 )
		return false;
	
	int j=n-1;
	while( v[i-1]>v[j] )
		j-=1;
	
	swap(v[i-1], v[j]);
	j = n-1;
	while( i<j ){
		swap(v[i], v[j]);
		i+=1;
		j-=1;
	}
	return true;
}
int main(){
	int v[8];
	int n;
	scanf("%d", &n);
	
	for(int i=0; i<n; ++i){
		v[i] = i+1;
	}
	
	while( true ){
		for(int i=0; i<n; ++i)
			printf("%d ", v[i]);
		printf("\n"); 
	
		if( next_permutation(v, n) == false )
			break;
	}
	
	
	
	return 0;
}
