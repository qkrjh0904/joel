#include <iostream>

using namespace std;

void answer(){
	int n;
	cin>>n;

	int answer=0;
	for(int i=5; i<=n; i*=5)
		answer += n/i;
	cout<<answer<<endl;
	
//	int cnt5 = n/5;
//	int cnt25 = n/25;
//	int cnt125 = n/125;
//	cout<< cnt5+cnt25+cnt125 <<endl;
}

int main(void){
	answer();
	return 0;
}
