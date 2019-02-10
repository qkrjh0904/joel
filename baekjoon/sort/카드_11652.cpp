#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void answer(){
	int n;
	cin>> n;
	
	vector<long long> v(n);
	for(int i=0; i<n; ++i){
		cin>>v[i];
	}
	sort(v.begin(), v.end());
	
	vector<int> cnt(n);
	cnt[0]=1;
	for(int i=1; i<n; ++i){
		if( v[i]==v[i-1] )
			cnt[i] = cnt[i-1]+1;
		else
			cnt[i]=1;
	}
//	for(int i=0; i<n; i++)
//		cout<<v[i]<<' ';
//	cout<<endl;
//	for(int i=0; i<n; i++)
//		cout<<cnt[i]<<' ';
//	cout<<endl;
	
	int max=1;
	for(int i=0; i<n; ++i){
		if( max<cnt[i] )
			max=cnt[i];
	}
	for(int i=0; i<n; ++i){
		if( max==cnt[i] ){
			cout<<v[i]<<'\n';
			break;
		}
	}
} 

int main(){
	answer();
	return 0;
}
