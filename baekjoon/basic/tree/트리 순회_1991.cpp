#include <iostream>

using namespace std;

int node[26][2];
void pre_order(int n){
	if( n==-1 )	return;
	cout<<(char)(n+'A');
	pre_order(node[n][0]);
	pre_order(node[n][1]);
}
void in_order(int n){
	if( n==-1 )	return;
	in_order(node[n][0]);
	cout<<(char)(n+'A');
	in_order(node[n][1]);
}
void post_order(int n){
	if( n==-1 )	return;
	post_order(node[n][0]);
	post_order(node[n][1]);
	cout<<(char)(n+'A');
}
int main(){
	int n;
	scanf("%d", &n);
	
	
	for(int i=0; i<n; ++i){
		char p, c1, c2;
		cin>>p>>c1>>c2;
		p = p-'A';
		
		if(c1=='.')
			node[p][0] = -1;
		else
			node[p][0] = c1-'A';
		
		if(c2=='.')
			node[p][1] = -1;
		else
			node[p][1] = c2-'A';
	}
	
	pre_order(0);
	cout<<endl;
	in_order(0);
	cout<<endl;
	post_order(0);

	return 0;
}
