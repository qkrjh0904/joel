#include <iostream>
#include <vector>
using namespace std;

int solution(vector<vector<int> > board)
{
    int answer = 0;
    //현재값이 1일때 좌측, 상단, 좌상단 중에 가장 작은 값+1을 현재값으로 넣으면 가장 큰 사각형을 구할 수 있다. 
    for(int i=1; i<board.size(); ++i){
		for(int j=1; j<board[0].size(); ++j){
			if(board[i][j]==1) 
				board[i][j] = min(board[i][j-1], min(board[i-1][j-1], board[i-1][j]))+1;
		}
	}
	
	int max_val=board[0][0];
	for(int i=0; i<board.size(); ++i){
		for(int j=0; j<board[0].size(); ++j){
//			cout<<board[i][j]<<' ';
			if(max_val<board[i][j])
				max_val = board[i][j];
		}
//		cout<<endl;
	}
	answer = max_val*max_val;
	return answer;
}

int main(void){
	
	vector<vector<int> > board = {{0,1,1,1},{1,1,1,1},{1,1,1,1},{0,0,1,0}};
	int answer = solution(board);
	cout<< answer << endl;

	return 0;
} 
