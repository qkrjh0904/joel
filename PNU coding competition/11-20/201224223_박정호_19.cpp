#include <iostream>
#include <vector> 

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    vector<int> day(progresses.size());
    for(int i=0; i<progresses.size(); ++i){
		day[i] = (100 - progresses[i])/speeds[i];	//남은 작업량에서 속도를 나눠 걸리는 일수를 계산. 
		if((100 - progresses[i])%speeds[i] != 0)	//조금 모자란다면 하루를 더 해 채운다. 
			day[i]++;
	}
	
	//기능 순서에 따라 날짜 배포일 맞춰준다.
	//예를들어 3,1,4일이 걸리면 두번째 기능은 첫번째 배포일에 맞춰야하므로 3,3,4일로 맞춰준다. 
	for(int i=1; i<day.size(); ++i){
		if(day[i] < day[i-1])
			day[i] = day[i-1];
	}
	
	//각 배포일마다 몇개의 기능이 배포되는지 계산한다. 
	int j=0;
	for(int i=1; i<day.size(); ++i){
		j++;
		if(day[i-1] < day[i]){
			answer.push_back(j);
			j=0;
		}
	}
	answer.push_back(j+1);
    
    return answer;
}

int main(void){
	
	vector<int> progresses = {93, 30, 55};
	vector<int> speeds = {1, 30, 5};
	
	vector<int> answer = solution(progresses, speeds);
	
	for(int i=0; i<answer.size(); ++i)
		cout<< answer[i] <<' ';
	cout<<endl;
	
	
	return 0;
}
