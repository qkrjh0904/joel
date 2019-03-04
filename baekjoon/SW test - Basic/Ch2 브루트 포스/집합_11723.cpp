#include <iostream>
#include <string>

using namespace std;

int s=0;
void add(int num){
	s = s | (1<<num);
}

void remove(int num){
	s = s & ~(1<<num);
}

void toggle(int num){
	s = s ^ (1<<num);
}

void answer(string op, int num){
	if( op == "add" )
		add(num);
	else if( op == "remove" )
		remove(num);
	else if( op == "check" ){
		if( ( s & (1<<num) ) > 0 )
			cout<<1<<'\n';
		else
			cout<<0<<'\n';
	}
	else if( op == "toggle" )
		toggle(num);
	else if( op == "all" )
		s = 0b11111111111111111111;
	else if( op == "empty" )
		s = 0;
}

int main(){
	int n;
	scanf("%d", &n);
	for(int i=0; i<n; ++i){
		char op[111];
		scanf("%s", op);
		if(op=="all" || op=="empty"){
			answer(op, 0);
			continue;
		}
		int num;
		scanf("%d", &num);
		answer(op, num-1);
	}
	
	return 0;
}
