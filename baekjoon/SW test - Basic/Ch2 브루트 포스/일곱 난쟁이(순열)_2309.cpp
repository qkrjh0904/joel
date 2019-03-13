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
	
	vector<int> lie(9);
	lie[7] = lie[8] = 1;
	do{
		int temp = total;
		for(int i=0; i<9; ++i){
			if(lie[i]==1)
				temp -= v[i];
		}
		if(temp==100){
			for(int i=0; i<9; ++i){
				if(lie[i]==1)
					continue;
				else
					cout<<v[i]<<'\n';
			}
			break;
		}
	}while(next_permutation(lie.begin(), lie.end())); 
	
	
	
	return 0;
}
