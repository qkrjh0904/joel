#include <iostream>
#include <vector> 
#include <algorithm>

using namespace std;

int main(){
	
	vector<int> v(9);
	int total=0;
	for(int i=0; i<9; ++i){
		cin>>v[i];
		total += v[i];
	}
	
	sort(v.begin(), v.end());
	for(int i=0; i<8; ++i){
		for(int j=i+1; j<9; ++j){
			if( total-v[i]-v[j] == 100 ){
				for(int k=0; k<9; ++k){
					if( k!=i && k!=j ){
						cout<<v[k]<<'\n';
					}
				}
				return 0;
			}
		}
	}
	
	
	
	
	return 0;
}
