#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 1000001;
vector<bool> check(MAX);
vector<int> time(MAX);


int main(){
	
	int n, k;
	cin>>n>>k;
		
	queue<int> q1;
	queue<int> q2;
	q1.push(n);
	time[n] = 0;
	check[n] = true;
	
	while(!q1.empty()){
		int now = q1.front();
		q1.pop();
		if(now*2<MAX && check[now*2]==false){
			q1.push(now*2);
			check[now*2]=true;
			time[now*2] = time[now];
		}
		if(now-1>=0 && check[now-1]==false){
			q2.push(now-1);
			check[now-1]=true;
			time[now-1] = time[now]+1;
		}
		if(now+1<MAX && check[now+1]==false){
			q2.push(now+1);
			check[now+1]=true;
			time[now+1] = time[now]+1;
		}
		
		if(q1.empty()){
			q1 = q2;
			q2 = queue<int>();
		}
	}
	cout<<time[k]<<'\n';
	
	
	return 0;
}
