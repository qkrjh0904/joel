#include <iostream>
#include <string>

using namespace std;

void answer(int n) {
    if(n==0) {
        return;
    }
    if( n%2==0 ){
        answer( -(n/2) );
        cout<<0;
    } 
	else{
        if(n>0){
            answer( -(n/2) );
        }
		else{
            answer( (-n+1)/2 );
        }
        cout<<1;
    }
}
int main(){
    int n;
    cin>>n;
    if(n==0)
        cout<<0<<'\n';
	else
        answer(n);
    return 0;
}
