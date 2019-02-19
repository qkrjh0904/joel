#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	
	vector<int> num(n);
	vector<int> op;
	
	for(int i=0; i<n; ++i)
		scanf("%d", &num[i]);
	for(int i=0; i<4; ++i){
		int temp;
		scanf("%d", &temp);
		for(int j=0; j<temp; ++j)
			op.push_back(i);
	}
	
	long long mini=1000000000;
	long long maxi=0;
	int cnt=1;
	do{
		long long temp=num[0];
		for(int i=0; i<n-1; ++i){
			if( op[i]==0 ) temp+=num[i+1];
			else if( op[i]==1 ) temp-=num[i+1];
			else if( op[i]==2 ) temp*=num[i+1];
			else if( op[i]==3 ) temp/=num[i+1];
		}
		maxi = max(maxi, temp);
		mini = min(mini, temp);
	}while( next_permutation( op.begin(), op.end() ) );
	
	printf("%d\n%d\n\n", maxi, mini);
	
	
	return 0;
}
