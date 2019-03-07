#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 200000;
vector<bool> check(MAX+1);
vector<int> time(MAX+1);


int main(){
	
	int n, k;
	cin>>n>>k;
		
	queue<int> q;
	q.push(n);
	time[n] = 0;
	check[n] = true;
	
	while(!q.empty()){
		int now = q.front();
		q.pop();
		if(now-1>=0 && check[now-1]==false){
			q.push(now-1);
			check[now-1]=true;
			time[now-1] = time[now]+1;
		}
		if(now+1<MAX && check[now+1]==false){
			q.push(now+1);
			check[now+1]=true;
			time[now+1] = time[now]+1;
		}
		if(now*2<MAX && check[now*2]==false){
			q.push(now*2);
			check[now*2]=true;
			time[now*2] = time[now]+1;
		}
	}
	cout<<time[k]<<'\n';
	
	
	return 0;
}
