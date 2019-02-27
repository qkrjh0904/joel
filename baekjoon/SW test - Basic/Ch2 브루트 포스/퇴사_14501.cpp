#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
void go( vector<int> &time, vector<int> &pay, vector<int> &total_pay, int now, int sum_p ){
	if( now==n+1 ){
		total_pay.push_back(sum_p);
		return;
	}
	if( now>n+1 ){
		return;
	}
	go( time, pay, total_pay, now+time[now], sum_p+pay[now] );
	go( time, pay, total_pay, now+1, sum_p);
}

int main(){
	
	scanf("%d", &n);
	
	vector<int> time(n+1);
	vector<int> pay(n+1);
	vector<int> total_pay;
	
	for(int i=1; i<=n; ++i)
		cin >> time[i] >> pay[i];
	
	go(time, pay, total_pay, 1, 0);
	
	int ans=0;
	for(int x : total_pay){
//		cout<<x<<' ';
		ans = max(ans, x);
	}
//	cout<<endl;
	cout<<ans<<endl;
}
