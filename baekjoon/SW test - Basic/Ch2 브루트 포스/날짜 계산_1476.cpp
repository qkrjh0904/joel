#include <iostream>
#include <vector> 
#include <algorithm>

using namespace std;

int main(){
	
	int e, s, m;
	cin>>e>>s>>m;
	
	int cnt=1;
	int ne, ns, nm;
	ne = ns = nm = 1;
	while(true){
		if( ne==e && ns==s && nm==m ){
			cout<<cnt<<'\n';
			break;
		}
		cnt++;
		ne++;
		ns++;
		nm++;
		if(ne>15)
			ne = 1;
		if(ns>28)
			ns=1;
		if(nm>19)
			nm=1;
		
	}
	
	
	
	
	return 0;
}
