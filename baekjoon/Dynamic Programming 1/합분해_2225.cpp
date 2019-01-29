#include <iostream>

using namespace std;

long long d[201][201] = {0, };
long long answer(){
	
	long long answer = 0;
	long long mod = 1000000000;
	int n, k;
	cin>>n>>k;
	
	//k�� 0~n ������ ���� 
	//d[n][k] = k���� ������ ������ n�� �����
	for(int i=1; i<=k; ++i)
		d[0][i] = 1;
	for(int i=0; i<=n; ++i)
		d[i][1] = 1;

	
	for(int i=1; i<=n; ++i){
		for(int j=2; j<=k; ++j){
			for(int l=0; l<=i; ++l){
				d[i][j] += d[i-l][j-1];
				d[i][j] %= mod;
			}
		}
	}
	
	answer = d[n][k]%mod;
	
	return answer;
}

int main(void){
	cout<<answer()<<'\n';
	return 0;
} 
