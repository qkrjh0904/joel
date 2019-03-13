#include <iostream>

using namespace std;

int go(int sum, int goal){
	if(sum>goal)
		return 0;
	if(sum==goal)
		return 1;
		
	int now=0;
	for(int i=1; i<=3; ++i){
		now += go(sum+i, goal);
	}
	return now;
}

void solution(){
	int t;
	cin>>t;
	
	for(int i=0; i<t; ++i){
		int goal;
		cin>>goal;
		cout<<go(0, goal)<<'\n';
	}
}
int main(){
	solution();
	return 0;
}
