#include <iostream>
#include <vector>


using namespace std;

int solution(int n, vector<int> cores) {
    int answer = 0;
    
    int time=0;
    vector<int> cores_state(cores.size());
	
	//i는 처리할 작업의 번호이다. 
	for(int i=1; i<=n;){
		for(int j=0; j<cores.size(); ++j){	
			if(time%cores[j]==0){	//각 코어마다 걸리는 시간을 나눈 나머지가 0일때 새로운 작업 가능. 
				cores_state[j] = i;
				i++;
			}
		}
		//현재 코어 상태 
//		cout<<cores_state[0]<<' '<<cores_state[1]<<' '<<cores_state[2]<<endl;
		time++;
	}
    
    //마지막 작업인 n이 들어있는 코어를 찾기위해 코어 상태에서 n과 같은 코어를 찾는다. 
    for(int i=0; i<cores.size(); ++i){
		if(cores_state[i] == n){	//n과 같을때의 코어를 반환해준다. 
			answer = i+1;			//0부터 시작하므로 1을 더해준다. 
			break;
		}
	}
    return answer;
}

int main(void){
	
	int n = 6;		//처리해야할 작업 수
	vector<int> cores = {1, 2, 3}; 
	
	int answer = solution(n, cores);
	cout<< answer <<endl;
	
	return 0;
}
