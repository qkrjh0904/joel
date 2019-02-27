#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int cnt=0;
int goal=0;
int n=0;

void go(int sum, vector<int> &v, int i){
	if(sum==goal && i==n){
		cnt++;
		return;
	}
	if(i==n)
		return;
		
	go(sum+v[i], v, i+1);
	go(sum, v, i+1);
}

int main(){
	scanf("%d %d", &n, &goal);
	
	vector<int> v(n);
	for(int i=0; i<n; ++i)
		cin>>v[i];
	
	sort(v.begin(), v.end());
	
	if(goal==0)
		cnt = -1;
	go(0, v, 0);
	cout<<cnt<<'\n';
}
