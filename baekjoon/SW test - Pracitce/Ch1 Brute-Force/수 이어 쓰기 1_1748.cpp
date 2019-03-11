#include <iostream>

using namespace std;

void solution(){
	int n;
	cin>>n;
	
	long long answer=0;
	
	if(n>9)
		answer += 9;
	else{
		answer += n;
		cout<<answer<<'\n';
		return;
	}

	if(n>99)
		answer += 90*2;
	else{
		answer += (n-9)*2;
		cout<<answer<<'\n';
		return;
	}
	
	if(n>999)
		answer += 900*3;
	else{
		answer += (n-99)*3;
		cout<<answer<<'\n';
		return;
	}
	
	if(n>9999)	
		answer += 9000*4;
	else{
		answer += (n-999)*4;
		cout<<answer<<'\n';
		return;
	}
	
	if(n>99999)
		answer += 90000*5;
	else{
		answer += (n-9999)*5;
		cout<<answer<<'\n';
		return;
	}
	
	if(n>999999)
		answer += 900000*6;
	else{
		answer += (n-99999)*6;
		cout<<answer<<'\n';
		return;
	}
	
	if(n>9999999)
		answer += 9000000*7;
	else{
		answer += (n-999999)*7;
		cout<<answer<<'\n';
		return;
	}
	
	if(n>99999999){
		answer += (90000000*8 + 9);
		cout<<answer<<'\n';
	}
	else{
		answer += (n-9999999)*8;
		cout<<answer<<'\n';
		return;
	}
	
	
}

int main(){
	solution();
	return 0;
}
