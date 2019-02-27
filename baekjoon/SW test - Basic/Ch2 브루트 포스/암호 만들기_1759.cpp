#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool check(string password){
	int mo=0;
	int ja=0;
	
	for( char x : password ){
		if( x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u' )
			mo++;
		else
			ja++; 
	}
	
	return mo>=1 && ja>=2;
}

void go(int n, vector<char> &alpha, string password, int i){
	if(password.length() == n){
		if( check(password) )
			cout<<password<<'\n';
		return;
	}
	if(i>=alpha.size())
		return;
		
	go(n, alpha, password+alpha[i], i+1);
	go(n, alpha, password, i+1);
	
}

int main(){

	int L, C;
	scanf("%d %d", &L, &C);
	
	vector<char> c(C);
	for(int i=0; i<C; ++i)
		cin>>c[i];
	
	sort(c.begin(), c.end());	
	
	string s="";
	go(L, c, s, 0);
}
