#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int solution(int leng, int limit_w, vector<int> truck_w){
	int total_time=0;	//총 걸리는 시간 반환값
	int no_truck = limit_w;	//다리에 아무것도 없을 때 버틸 수 있는 하중. 
	
	queue<int> truck;	//입력받은 트럭 무게를 큐 컨테이너에 차례로 저장 
	for(int i=0; i<truck_w.size(); ++i)
		truck.push(truck_w[i]);

	vector<int> bridge(leng);	//다리 길이 설정, 초기화 상태는 모두 0으로. 
	
//	//대기중인 첫번째 트럭 출력
//	cout<<truck.front()<<"		";
//	//다리 상태, 다리한계, 시간 출력
//	for(int i=leng-1; i>=0; --i)
//		cout<<bridge[i]<<' ';
//	cout<<"		"<<limit_w<<"		"<<total_time<<endl; 
	
	while(!truck.empty()){	//대기 트럭이 없을때까지. 
			
		bridge.erase(bridge.begin());				//맨 앞에있는 수 제거
		
		limit_w = no_truck;				//다리 한계 하중을 구하기 위해 다시 초기화. 
		for(int i=0; i<bridge.size(); ++i){		//다리가 견딜 수 있는 하중 계산. 
			limit_w -= bridge[i];
		}

		if(limit_w >= truck.front() && !truck.empty()){		//다리가 다음에 들어올 트럭이 있으며, 이를 버틸 수 있다면 코드실행 
			bridge.push_back(truck.front());//다리에 대기 트럭 큐에 있는 가장 첫번째 트럭 넣음.
			limit_w -= truck.front();		//진입한 트럭무게만큼 하중 한계에서 뺌. 
			truck.pop();					//대기 트럭 큐에서 진입한 트럭 제거.  
		}
		else{	//다리가 다음에 들어올 트럭을 버틸 수 없다면 다음 코드 실행 
			bridge.push_back(0);			//트럭이 진입하지 못하므로 0을 넣어줌.
		}
		total_time++;	//1초 증가 
		
//		/************************************************************/
//		//대기중인 첫번째 트럭 출력
//		cout<<truck.front()<<"		";
//		//다리 상태, 다리한계, 시간 출력
//		for(int i=leng-1; i>=0; --i)
//			cout<<bridge[i]<<' ';
//		cout<<"		"<<limit_w<<"		"<<total_time<<endl; 
//		/************************************************************/
		
	}
	total_time += leng;
	
	return total_time;
} 

int main(void){
	
	int leng = 2;		 				//다리길이 예시 
	int limit_w = 10;					//다리 한계 예시 
	vector<int> truck_w = {7,4,5,6};	//트럭 무게 예시 
	
	int result;
	result = solution(leng, limit_w, truck_w);
	
	cout<< result <<endl;
	
	
	return 0;
}
