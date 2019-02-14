#include <iostream>
#include <string>

using namespace std;

int d[5001];
int mod = 1000000;
int answer(){
	string s;
    cin >> s;
    int n = s.size();
    s = " " + s;
    d[0] = 1;
    for (int i=1; i<=n; i++) {
        int x = s[i] - '0';
        if (1 <= x && x <= 9) {
            d[i] += d[i-1];
            d[i] %= mod;
        }
        if (i==1) {
            continue;
        }
        if (s[i-1] == '0') {
            continue;
        }
        x = (s[i-1]-'0')*10 + (s[i]-'0');
        if (10 <= x && x <= 26) {
            d[i] += d[i-2];
            d[i] %= mod;
        }
    }
    cout << d[n] << '\n';
	
	/*
	int n[500] = {0, };
	int d[5001] = {0, };

	int mod = 1000000;
	long long answer=0;
	string num;
	cin>>num;
	int length=num.size();
	
	for(int i=0; i<length; ++i){
		if( num[i]<'0' || num[i]>'9' )
			return 0;
		if( num[0]=='0' )
			return 0;
		n[i] = num[i]-'0';
	}
	
	d[0] = 1;
	d[1] = 1;
	if( n[0]==1 || n[0]==2 )
		d[1] = 2;
	
	for(int i=2; i<length; ++i){
		if( n[i]==0 ){
			if(n[i-1]<1 || n[i-1]>2) 
				return 0;
			d[i] = d[i-2];
		}
		else{
			d[i] = d[i-1];
			if(n[i-1]==1 || n[i-1]==2){
				d[i] += d[i-2];
			}
		}
		d[i] %= mod;
	}
	for(int i=0; i<length; ++i)
		cout<<d[i]<<' ';
	cout<<endl;
	answer = d[length-1];
	return answer;
	*/
}

int main(void){
	answer();

	return 0;
} 
