#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string> 
#include <stack>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    //체스판 만들기. 
    vector< vector<int> > board(n, vector<int>(5, 0));
    
    for(int i=0; i<n; ++i){
		for(int j=0; j<n; ++j)
			cout<<board[i][j]<<' ';
		cout<<endl;
	}
    
    
    return answer;
}

int main(void){

	int n=4;
	int answer = solution(n);
	cout<< answer <<endl;
	return 0;
} 
