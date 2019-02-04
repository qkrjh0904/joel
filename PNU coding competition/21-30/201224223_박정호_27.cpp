#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    vector<int> temp;	//잘라서 저장할 임시 벡터 
	for(int i=0; i<commands.size(); ++i){
		for(int j=commands[i][0]-1; j<=commands[i][1]-1; ++j){
			temp.push_back(array[j]);		//차례로 자른부분 temp에 넣기 
//			cout<<array[j]<<' ';
		}
//		cout<<endl;
		sort(temp.begin(), temp.end());		//자른부분 정렬 
		answer.push_back(temp[commands[i][2]-1]);	//정렬 후 k번째 숫자 answer에 넣기. 
		temp.clear();	//temp 초기화 
	} 
    
    return answer;
}

int main(void){
	vector<int> array = {1, 5, 2, 6, 3, 7, 4};
	vector<vector<int>> commands = {{2, 5, 3},{4, 4, 1},{1, 7, 3}};
	vector<int> answer = solution(array, commands);

	for(int i=0; i<answer.size(); ++i)
		cout<<answer[i]<<' ';
	cout<<endl;

	return 0;
}
