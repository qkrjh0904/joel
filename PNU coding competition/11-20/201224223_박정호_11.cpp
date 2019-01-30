#include <iostream>
#include <vector> 
#include <cmath>

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    
    //전체 작업량에서 야근시간을 뺀 작업량의 평균으로 지수를 맞춰준다.
	//전체 작업량 구하기.
	int total_works = 0;
	for(int i=0; i<works.size(); ++i)
		total_works += works[i];
		
	//전체 작업량에서 야근시간 빼기.
	int remain_works = 0;
	remain_works = total_works - n;
	
	//남은 작업량이 0이하 이면 피로도 0
	if(remain_works <= 0){
		answer = 0;
		return answer;
	}
	
	//남은 작업량의 평균구하기.
	int rw_avg = 0;
	rw_avg = remain_works/works.size();
	
	//works의 모든 작업량을 평균으로 맞춰주기.
	//우선순위는 가장 큰 수부터. 
	int time = n;
	while(time!=0){
		int max_work = works[0];	//가장 큰수 초기화를 works의 첫번째 수로 
		for(int i=1; i<works.size(); ++i){	//works에서 가장 큰 수 찾기. 
			if(max_work < works[i])
				max_work = works[i];
		}
		for(int i=0; i<works.size(); ++i){	//works에서 가장 큰수를 1씩 빼고, 시간도 1씩 빼기. 
			if(works[i] == max_work){
				works[i]--;
				break;
			}
		}
		time--;
	}

	
	//야근 후의 피로도 계산.
	for(int i=0; i<works.size(); ++i){
		answer += pow(works[i], 2);
	} 
    
    return answer;
}

int main(void){
	
	int n = 4;
	vector<int> works = {4, 3, 3};
	
	long long answer = solution(n, works);
	cout<< answer << endl;
	
	return 0;
}
