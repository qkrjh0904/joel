#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

	int L, C;
	scanf("%d %d", &L, &C);
	
	vector<char> c(C);
	for(int i=0; i<C; ++i)
		cin>>c[i];
	
	for(int i=0; i<C; ++i)
		cout<<c[i]<<' ';
	cout<<endl;
	
	sort(c.begin(), c.end());	
	for(int i=0; i<C; ++i)
		cout<<c[i]<<' ';
	cout<<endl;
		
}
