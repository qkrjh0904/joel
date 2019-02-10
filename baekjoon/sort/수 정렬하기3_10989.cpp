#include <iostream>

using namespace std;

int v[10001];
void answer(){
	int n;
	cin>> n;
	
	
	//	cin과 cout을 사용했을 때는 시간초과로 실패함. 
	
	int num;
	for(int i=0; i<n; ++i){
		scanf("%d", &num);
		v[num]+=1;
	}
	
	for(int i=1; i<=10000; ++i){
		if(v[i]>0){
			for(int j=0; j<v[i]; ++j)
				printf("%d\n", i);
		}
	}
} 

int main(){
	answer();
	return 0;
}
