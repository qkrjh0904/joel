#include <iostream>
#include <vector>

using namespace std;

int solution(vector<int> budgets, int M) {
    int answer = 0;	//상한액
    
    //총 요구 예산액보다 배정된 예산액이 많은 경우 가장 큰 예산액을 신청한 지역이 상한액이 된다. 
    int total_require=0;	//총 요구 예산액 
    for(int i=0; i<budgets.size(); ++i){
		total_require += budgets[i];
	}
	if(M >= total_require){	//배정된 예산액이 그 이상이면 
		answer = budgets[0];	//가장 큰 예산을 요구한 금액이 상한액이 된다. 
		for(int i=1; i<budgets.size(); ++i)
			if(answer < budgets[i])
				answer = budgets[i];
		return answer;	//상한액 반환 
	}
	
	//예산액이 부족한 경우 먼저 (총예산/지방의 수) 만큼 공정하게 배분 
	int avg=0;		//공정한 배분액 
	int avg_r=0; 	//배분 후 남은 금액 
	avg = M/budgets.size();
	avg_r = M%budgets.size();
//	cout<<"avg : " <<avg<<" avg_r : "<<avg_r<<endl;
	
	
	//배분 후 남은 예산액 혹은 부족한 예산 액 계산. 
	for(int i=0; i<budgets.size(); ++i){
		if(avg-budgets[i] > 0){
			avg_r += (avg-budgets[i]);
			budgets[i] = 0;
		}
		else{
			budgets[i] = budgets[i] - avg;
		}
	}
//	cout<<"avg : " <<avg<<" avg_r : "<<avg_r<<endl;
	//첫번째 배분액 기록
	answer += avg; 
	//배분후 상태 출력 
	int cnt=0;
	for(int i=0; i<budgets.size(); ++i){
//		cout<<budgets[i]<<' ';
		if(budgets[i] > 0)
			 cnt++;
	}
//	cout<<endl;
//	cout<<"avg_r : "<<avg_r<<endl;
//	cout<<"부족한 지방 수  : "<<cnt<<endl;
	avg = avg_r/cnt;
	avg_r %= cnt;
//	cout<<"avg : " <<avg<<" avg_r : "<<avg_r<<endl;
	
	while(avg>0){
		for(int i=0; i<budgets.size(); ++i){
			if(budgets[i] > 0){
				if(avg - budgets[i] > 0){
					avg_r += (avg-budgets[i]);
					budgets[i] = 0;
				}
				else{
					budgets[i] = budgets[i] - avg;
				}
					
			}
		}
//		cout<<"avg : " <<avg<<" avg_r : "<<avg_r<<endl;
//		cout<<"answer : "<<answer<<endl;
//		cout<<"avg : " <<avg<<" avg_r : "<<avg_r<<endl;
		answer += avg; 
		
		//배분후 상태 출력 
		cnt=0;
		for(int i=0; i<budgets.size(); ++i){
//			cout<<budgets[i]<<' ';
			if(budgets[i] > 0)
				 cnt++;
		}
//		cout<<endl;
//		cout<<"cnt : "<<cnt<<endl;
		avg = avg_r/cnt;
		avg_r = avg_r%cnt;
//		cout<<"avg : " <<avg<<" avg_r : "<<avg_r<<endl;
		
	}


    return answer;
}

int main(void){
	
	vector<int> budgets = {10, 20, 30, 40, 50};	//예산 벡터 
	int M = 147;	//총예산
	
	int answer = solution(budgets, M);
	cout<< answer <<endl; 
	
	return 0;
}
