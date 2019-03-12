#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int n;
int v[20][20];
int go(int index, vector<int> &first, vector<int> &second){
	if(index==n){
		if(first.size() != n/2) return -1;
		if(second.size() != n/2) return -1;
		
		int t1=0;
		int t2=0;
		for(int i=0; i<n/2; ++i){
			for(int j=0; j<n/2; ++j){
				if(i==j) continue;
				t1 += v[first[i]][first[j]];
				t2 += v[second[i]][second[j]];
			}
		}
		return abs(t1-t2);
	}
	int ans=-1;
	first.push_back(index);
	int t1 = go(index+1, first, second);
	if(ans==-1 || (t1!=-1 && ans>t1)){
		ans = t1;
	}
	first.pop_back();
	second.push_back(index);
	int t2 = go(index+1, first, second);
	if(ans==-1 || (t2!=-1 && ans>t2)){
		ans = t2;
	}
	second.pop_back();
	return ans;
}

void solution(){
	cin>>n;
	for(int i=0; i<n; ++i){
		for(int j=0; j<n; ++j){
			cin>>v[i][j];
		}
	}
	
	vector<int> first, second;
	cout<<go(0, first, second)<<'\n';
	
}

int main(){
	solution();
	return 0;
}
