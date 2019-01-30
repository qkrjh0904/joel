#include <iostream>
#include <vector>


using namespace std;

int solution(int n, vector<int> cores) {
    int answer = 0;
    
    int time=0;
    vector<int> cores_state(cores.size());
	
	//i�� ó���� �۾��� ��ȣ�̴�. 
	for(int i=1; i<=n;){
		for(int j=0; j<cores.size(); ++j){	
			if(time%cores[j]==0){	//�� �ھ�� �ɸ��� �ð��� ���� �������� 0�϶� ���ο� �۾� ����. 
				cores_state[j] = i;
				i++;
			}
		}
		//���� �ھ� ���� 
//		cout<<cores_state[0]<<' '<<cores_state[1]<<' '<<cores_state[2]<<endl;
		time++;
	}
    
    //������ �۾��� n�� ����ִ� �ھ ã������ �ھ� ���¿��� n�� ���� �ھ ã�´�. 
    for(int i=0; i<cores.size(); ++i){
		if(cores_state[i] == n){	//n�� �������� �ھ ��ȯ���ش�. 
			answer = i+1;			//0���� �����ϹǷ� 1�� �����ش�. 
			break;
		}
	}
    return answer;
}

int main(void){
	
	int n = 6;		//ó���ؾ��� �۾� ��
	vector<int> cores = {1, 2, 3}; 
	
	int answer = solution(n, cores);
	cout<< answer <<endl;
	
	return 0;
}
