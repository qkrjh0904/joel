#include <iostream>

using namespace std;

long long a[2][100001];
long long d[3][100001];
int answer(){
	int n;
	cin>>n;
	
	int num;
	for(int i=0; i<2; ++i){
		for(int j=1; j<=n; ++j){
			cin>>num;
			a[i][j] = num;
		}
	}
	
	//d[0][n]: 아무것도 떼지않음. d[1][n]: 위에것 뗌 d[2][n]: 아래것 뗌 
	d[0][0] = d[1][0] = d[2][0] = 0;
	for(int i=1; i<=n; ++i){
		d[0][i] = max(d[0][i-1], max(d[1][i-1], d[2][i-1])); 
		d[1][i] = max(d[0][i-1], d[2][i-1]) + a[0][i];
		d[2][i] = max(d[0][i-1], d[1][i-1]) + a[1][i];
	}
	
	long long answer=0;
	for(int i=1; i<=n; ++i){
		answer = max(max(answer, d[0][n]), max(d[1][n], d[2][n]));
	}
	
	cout<<answer<<'\n';
	
}

int main(void){
	int t;
	cin>>t;
	for(int i=0; i<t; ++i)
		answer();
	
	return 0;
}
