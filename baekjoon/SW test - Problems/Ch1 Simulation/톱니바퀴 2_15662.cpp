#include <iostream>
#include <vector>

using namespace std;

int T;
int gear[1001][8] = {0, };
vector<bool> state(1000);
vector<bool> check(1001);

void gearMove(int num, int direction){
	int temp;
	if( direction == 1 ){
		temp = gear[num][7];
		for(int i=6; i>=0; --i){
			gear[num][i+1] = gear[num][i];
		}
		gear[num][0] = temp;
	}
	else{
		temp = gear[num][0];
		for(int i=0; i<=6; ++i){
			gear[num][i] = gear[num][i+1];
		}
		gear[num][7] = temp;
	}
}

void gearState(){
	for(int i=1; i<T; ++i){
		if( gear[i][2] != gear[i+1][6] )
			state[i] = true;
	}
}

void gearSimulation(int num, int direction){
	gearMove(num, direction);
	check[num] = true;
	
	if(num-1 >= 1 && check[num-1]==false && state[num-1]==true)
		gearSimulation(num-1, direction*-1);
	if(num+1 <= T && check[num+1]==false && state[num]==true)
		gearSimulation(num+1, direction*-1);
}

void reset(){
	
	for(int i=1; i<T; ++i){
		state[i] = false;
	}
	
	for(int i=1; i<=T; ++i){
		check[i] = false;
	}
}

void solution(){
	
	scanf("%d", &T); 
	for(int i=1; i<=T; ++i){
		for(int j=0; j<8; ++j){
			int input;	// N±ØÀº 0, S±ØÀº 1 
			scanf("%1d", &input);
			gear[i][j] = input;
		}
	}
	int k;
	scanf("%d", &k);
	while( k!=0 ){
		k--;
		
		int num, direction;
		scanf("%d %d", &num, &direction);
		
		reset();
		
		gearState();
		gearSimulation(num, direction);
	}
	int answer=0;
	for(int i=1; i<=T; ++i){
		if( gear[i][0] == 1 )
			answer++;
	}
	printf("%d\n", answer);
}

int main(){
	solution();
	return 0;
}
