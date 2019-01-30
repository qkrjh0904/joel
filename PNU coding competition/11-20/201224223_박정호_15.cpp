#include <iostream>
#include <vector>

using namespace std;

int solution(vector<int> budgets, int M) {
    int answer = 0;	//���Ѿ�
    
    //�� �䱸 ����׺��� ������ ������� ���� ��� ���� ū ������� ��û�� ������ ���Ѿ��� �ȴ�. 
    int total_require=0;	//�� �䱸 ����� 
    for(int i=0; i<budgets.size(); ++i){
		total_require += budgets[i];
	}
	if(M >= total_require){	//������ ������� �� �̻��̸� 
		answer = budgets[0];	//���� ū ������ �䱸�� �ݾ��� ���Ѿ��� �ȴ�. 
		for(int i=1; i<budgets.size(); ++i)
			if(answer < budgets[i])
				answer = budgets[i];
		return answer;	//���Ѿ� ��ȯ 
	}
	
	//������� ������ ��� ���� (�ѿ���/������ ��) ��ŭ �����ϰ� ��� 
	int avg=0;		//������ ��о� 
	int avg_r=0; 	//��� �� ���� �ݾ� 
	avg = M/budgets.size();
	avg_r = M%budgets.size();
//	cout<<"avg : " <<avg<<" avg_r : "<<avg_r<<endl;
	
	
	//��� �� ���� ����� Ȥ�� ������ ���� �� ���. 
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
	//ù��° ��о� ���
	answer += avg; 
	//����� ���� ��� 
	int cnt=0;
	for(int i=0; i<budgets.size(); ++i){
//		cout<<budgets[i]<<' ';
		if(budgets[i] > 0)
			 cnt++;
	}
//	cout<<endl;
//	cout<<"avg_r : "<<avg_r<<endl;
//	cout<<"������ ���� ��  : "<<cnt<<endl;
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
		
		//����� ���� ��� 
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
	
	vector<int> budgets = {10, 20, 30, 40, 50};	//���� ���� 
	int M = 147;	//�ѿ���
	
	int answer = solution(budgets, M);
	cout<< answer <<endl; 
	
	return 0;
}
