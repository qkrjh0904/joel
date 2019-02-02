#include <iostream>
#include <vector>
using namespace std;

int solution(vector<vector<int> > board)
{
    int answer = 0;
    //���簪�� 1�϶� ����, ���, �»�� �߿� ���� ���� ��+1�� ���簪���� ������ ���� ū �簢���� ���� �� �ִ�. 
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
