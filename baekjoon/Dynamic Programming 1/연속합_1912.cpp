#include <iostream>

using namespace std;


int answer(void){
	
	int a[1001] = {0, };
	int d1[1001] = {0, };
	int d2[1001] = {0, }; 
	int d[1001] = {0, };

	int answer=0; 
	int n;
	cin>>n;
	
	int num;
	for(int i=1; i<=n; ++i){
		cin>>num;
		a[i] = num;
	}
	
	//Αυ°‘	 
	for(int i=1; i<=n; ++i){
		d1[i]=1;
		for(int j=1; j<=i; ++j){
			if( a[i] > a[j] && d1[i] < d1[j]+1 )
				d1[i] = d1[j]+1;
		}
	}
	
	for(int i=n; i>=1; --i){
		d2[i]=1;
		for(int j=n; j>=i; --j){
			if( a[i] > a[j] && d2[i] < d2[j]+1 )
				d2[i] = d2[j]+1;
		}
	}
	
	for(int i=1; i<=n; ++i){
		d[i] = d1[i]+d2[i]-1;
		if( answer < d[i] )
			answer = d[i];
	}

	
	
	return answer;
	
}

int main(void){

	cout<<answer()<<'\n';
	
	return 0;
}
