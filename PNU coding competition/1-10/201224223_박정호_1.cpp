#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answer){
	
	vector<int> ans1 = {1, 2, 3, 4, 5};					//1번 수포자가 찍는 방식 
	vector<int> ans2 = {2, 1, 2, 3, 2, 4, 2, 5};		//2번 수포자가 찍는 방식 
	vector<int> ans3 = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};	//3번 수포자가 찍는 방식 
	
	vector<int> winner;	//가장 많이 맞힌 사람을 기록하는 컨테이너 
	
	vector<int> score = {0,0,0};	//맞힌 점수 선언 및 초기화 
	
	
	for(int i=0; i<answer.size(); ++i){	//문제의 갯수만큼 반복해서 정답 확인 
	
		//수포자들이 찍은 답과 정답과 일치하면 1점 추가 
		if(answer[i] == ans1[i%5]) 	//1번 수포자는 5개의 규칙으로 반복 
			score[0]++;
		if(answer[i] == ans2[i%8])	//2번 수포자는 8개의 규칙으로 반복 
			score[1]++;
		if(answer[i] == ans3[i%10])	//3번 수포자는 10개의 규칙으로 반복 
			score[2]++;
	}

//	cout << "수포자 1은 " << score[0] << "문제를 맞췄습니다." << endl;
//	cout << "수포자 2은 " << score[1] << "문제를 맞췄습니다." << endl;
//	cout << "수포자 3은 " << score[2] << "문제를 맞췄습니다." << endl;
	
	//가장 높은 점수 선별. 
	int max_score = max(max(score[0], score[1]), score[2]);
	
	for(int i=0; i<3; ++i){
		if(score[i] == max_score)
			winner.push_back(i+1);
	}
	
	return winner;
	
}

int main(void){

	vector<int> answer = {1,2,3,4,5};	//정답 예시 
	
	vector<int> winner;
	winner = solution(answer);
	
//	cout<<"따라서 가장 많은 문제를 맞힌 사람은 수포자 ";
	for(int i=0; i<winner.size(); ++i)
		cout<< winner[i] <<endl;
//	cout<<" 입니다."<<endl;
	
	
	return 0;
}
