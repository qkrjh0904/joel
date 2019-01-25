#include <iostream>

using namespace std;

int a[10001] = {0, };
int d[10001][3];
int answer(void){
	
	int n;
	cin>>n;
	
	int num;
	for(int i=1; i<=n; ++i){
		cin>>num;
		a[i] = num;
	}
	
	for(int i=1; i<=n; ++i){
		d[i][0] = max(d[i-1][0], max(d[i-1][1], d[i-1][2]));
		d[i][1] = d[i-1][0] + a[i];
		d[i][2] = d[i-1][1] + a[i];
	}
	
	int answer = max(d[n][0], max(d[n][1], d[n][2]));
	return answer;
	
}

int main(void){

	cout<<answer()<<'\n';
	
	return 0;
}
