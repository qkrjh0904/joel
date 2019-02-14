#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;
vector<bool> check(1001);
int cnt=0;

void DFS(int n){
	check[n] = true;
	
	int x = v[n];
	if( check[x]==false )
		DFS(x);
	else
		cnt++;
}

void answer(){

	int a, p;
	scanf("%d %d", &a, &p);
	v.push_back(a);
	
	while(true){
		int temp, n=1;
		int input=0;
		while( a!=0 ){
			temp = a%10;
			a /= 10;
			for(int i=0; i<p; ++i){
				n *= temp;
			}
			input += n;
			n=1;
		}
		
		for(int i=0; i<v.size(); ++i){
			if( v[i]==input ){
				
				printf("%d\n", i);
				return;
			}
		}
		
		v.push_back(input);
		a = input;
		input=0;
	}
	
}

int main(){
	answer();
	return 0;
}
