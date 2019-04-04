#include <iostream>

using namespace std;

int a[20][20] = {0, };
int dice[6] = {0, }; //��, �Ʒ�, ��, ��, ��, �� 
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

void diceRolling(int input){
	int temp; 
	if(input==1){		//���� 
		temp = dice[0];
		dice[0] = dice[3];
		dice[3] = dice[1];
		dice[1] = dice[2];
		dice[2] = temp;
	}
	else if(input==2){	//���� 
		temp = dice[0];
		dice[0] = dice[2];
		dice[2] = dice[1];
		dice[1] = dice[3];
		dice[3] = temp;
	}
	else if(input==3){	//���� 
		temp = dice[0];
		dice[0] = dice[4];
		dice[4] = dice[1];
		dice[1] = dice[5];
		dice[5] = temp;		
	}
	else if(input==4){	//���� 
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
		if( a[x][y] == 0 ){	//�̵��� ĭ�� ���� 0�̸� dice�� �Ʒ��� ���� 
			a[x][y] = dice[1];
		}
		else{ //�̵��� ĭ�� ���� 0�� �ƴ϶�� dice�� �Ʒ��鿡 ĭ�� �� ���� 
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
