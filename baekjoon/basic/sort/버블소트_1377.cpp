#include <iostream>
#include <algorithm>
#include <vector> 

using namespace std;

void answer(){
	int n;
	scanf("%d",&n);
	
	vector<pair<int, int>> v(n);
	for(int i=0; i<n; ++i){
		scanf("%d", &v[i].first);
		v[i].second = i;
	}
	sort(v.begin(), v.end());
	
	int max=0;
	for(int i=0; i<n; ++i){
		if(max < v[i].second-i){
			max = v[i].second-i;
		}
	}
	printf("%d\n", max+1);
} 

int main(){
	answer();
	return 0;
}
