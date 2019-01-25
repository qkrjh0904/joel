#include <iostream>

using namespace std;


int answer(void){
	
	int a[1001] = {0, };
	int d[1001] = {0, };

	int answer=0; 
	int n;
	cin>>n;
	
	int num;
	for(int i=1; i<=n; ++i){
		cin>>num;
		a[i] = num;
	}
	
	for(int i=1; i<=n; ++i){
		d[i]=1;
		for(int j=1; j<=i; ++j){
			if( (a[i]>a[j]) && (d[i]<d[j]+1) ){
				d[i] = d[j]+1;
			}
		}
	}
	
	for(int i=1; i<=n; ++i){
		if(answer < d[i])
			answer = d[i];
	}
	return answer;
	
}

int main(void){

	cout<<answer()<<'\n';
	
	return 0;
}
