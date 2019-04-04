#include <iostream>

using namespace std;

int a[20][20] = {0, };
int dice[6] = {0, }; //위, 아래, 동, 서, 남, 북 
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

void diceRolling(int input){
	int temp; 
	if(input==1){		//동쪽 
		temp = dice[0];
		dice[0] = dice[3];
		dice[3] = dice[1];
		dice[1] = dice[2];
		dice[2] = temp;
	}
	else if(input==2){	//서쪽 
		temp = dice[0];
		dice[0] = dice[2];
		dice[2] = dice[1];
		dice[1] = dice[3];
		dice[3] = temp;
	}
	else if(input==3){	//북쪽 
		temp = dice[0];
		dice[0] = dice[4];
		dice[4] = dice[1];
		dice[1] = dice[5];
		dice[5] = temp;		
	}
	else if(input==4){	//남쪽 
		temp = dice[0];
		dice[0] = dice[5];
		dice[5] = dice[1];
		dice[1] = dice[4];
		dice[4] = temp;
	}
}

bool currentXY(int &x, int &y, int input, int n, int m){
	if(input==1){
		if(y+1>=m)
			return true;
		y++;
	}
	else if(input==2){
		if(y-1<0)
			return true;
		y--;
	}
	else if(input==3){
		if(x-1<0)
			return true;
		x--;
	}
	else if(input==4){
		if(x+1>=n)
			return true;
		x++;
	}
	return false;
}

void solution(){
	int n, m, x, y, k;
	scanf("%d %d %d %d %d", &n, &m, &x, &y, &k);
	for(int i=0; i<n; ++i){
		for(int j=0; j<m; ++j){
			int input;
			scanf("%d", &input);
			a[i][j] = input;
		}
	}
	while( k!=0 ){
		k--;
		int input;
		scanf("%d", &input);
		if( currentXY(x, y, input, n, m) )
			continue;
		diceRolling( input );
//		cout<<"("<<x<<", "<<y<<")"<<'\n';
		if( a[x][y] == 0 ){	//이동한 칸의 수가 0이면 dice의 아랫면 복사 
			a[x][y] = dice[1];
		}
		else{ //이동한 칸의 수가 0이 아니라면 dice의 아랫면에 칸의 수 복사 
			dice[1] = a[x][y];
			a[x][y] = 0; 
		}
		printf("%d\n", dice[0]);
		
	}
}

int main(){
	solution();
	return 0;
}
