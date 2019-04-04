#include <iostream>

using namespace std;

int gear[5][8] = {0, };
bool state[3] = {false, };
bool check[5] = {false, };

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
	for(int i=1; i<4; ++i){
		if( gear[i][2] != gear[i+1][6] )
			state[i-1] = true;
	}
}

void stateReset(){
	for(int i=0; i<3; ++i){
		state[i] = false;
	}
}

void checkReset(){
	for(int i=1; i<5; ++i){
		check[i] = false;
	}
}

void gearSimulation(int num, int direction){
	gearMove(num, direction);
	check[num] = true;
	
	if(num-1 >= 1 && check[num-1]==false && state[num-2]==true)
		gearSimulation(num-1, direction*-1);
	if(num+1 <= 4 && check[num+1]==false && state[num-1]==true)
		gearSimulation(num+1, direction*-1);
}

void solution(){
	for(int i=1; i<=4; ++i){
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
		
		stateReset();
		checkReset();
		
		gearState();
		gearSimulation(num, direction);	
	}
	int answer=0;
	if( gear[1][0]==1 )
		answer+=1;
	if( gear[2][0]==1 )
		answer+=2;
	if( gear[3][0]==1 )
		answer+=4;
	if( gear[4][0]==1 )
		answer+=8;
	printf("%d\n", answer);
}

int main(){
	solution();
	return 0;
}
