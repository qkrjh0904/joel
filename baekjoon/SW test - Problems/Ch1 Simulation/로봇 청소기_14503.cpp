#include <iostream>
#include <vector>

using namespace std;

vector< vector<int> > room(50, vector<int>(50));
vector<int> state(4);

bool check(int &r, int &c, int &d){
	if( d==0 ){
		if( state[3]==0 ){
			d = 3;
			c--;
		}
		else if( state[2]==0 ){
			d = 2;
			r++;
		}
		else if( state[1]==0 ){
			d = 1;
			c++;
		}
		else if( state[0]==0 ){
			d = 0;
			r--;
		}
		else{
			if( state[2]==1 ){
				return false;
			}
			else{
				r++;
			}
		}
	}else if( d==1 ){
		if( state[0]==0 ){
			d = 0;
			r--;
		}
		else if( state[3]==0 ){
			d = 3;
			c--;
		}
		else if( state[2]==0 ){
			d = 2;
			r++;
		}
		else if( state[1]==0 ){
			d = 1;
			c++;
		}
		else{
			if( state[3]==1 ){
				return false;
			}
			else{
				c--;
			}
		}
	}else if( d==2 ){
		if( state[1]==0 ){
			d = 1;
			c++;
		}
		else if( state[0]==0 ){
			d = 0;
			r--;
		}
		else if( state[3]==0 ){
			d = 3;
			c--;
		}
		else if( state[2]==0 ){
			d = 2;
			r++;
		}
		else{
			if( state[0]==1 ){
				return false;
			}
			else{
				r--;
			}
		}
	}else if( d==3 ){
		if( state[2]==0 ){
			d = 2;
			r++;
		}
		else if( state[1]==0 ){
			d = 1;
			c++;
		}
		else if( state[0]==0 ){
			d = 0;
			r--;
		}
		else if( state[3]==0 ){
			d = 3;
			c--;
		}
		else{
			if( state[1]==1 ){
				return false;
			}
			else{
				c++;
			}
		}	
	}
	
	return true;
		
}

void clear(int r, int c, int &answer){
	room[r][c] = 2;
	answer++;
}

void wirteState(int r, int c){
	state[0] = room[r-1][c];
	state[1] = room[r][c+1];
	state[2] = room[r+1][c];
	state[3] = room[r][c-1];
}

void solution(){
	int n, m, r, c, d;
	scanf("%d %d %d %d %d", &n, &m, &r, &c, &d);	//ºÏ,µ¿,¼­,³² ¼ø¼­·Î 0,1,2,3 
	//ºóÄ­Àº 0, º®Àº 1
	for(int i=0; i<n; ++i){
		for(int j=0; j<m; ++j){
			int temp;
			scanf("%d", &temp);
			room[i][j] = temp;
		}
	}
//	cout<<endl;
	int answer=0;
	do{
		if( room[r][c]==0 )
			clear(r, c, answer);
		wirteState(r, c);
//		for(int i=0; i<n; ++i){
//			for(int j=0; j<m; ++j){
//				cout<<room[i][j]<<' ';
//			}cout<<endl;
//		}cout<<endl;
	}while( check(r, c, d) );
	
	printf("%d\n", answer);
	
}

int main(){
	solution();
	return 0;
}
