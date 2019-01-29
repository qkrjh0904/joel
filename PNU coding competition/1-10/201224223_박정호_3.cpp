#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int solution(int leng, int limit_w, vector<int> truck_w){
	int total_time=0;	//�� �ɸ��� �ð� ��ȯ��
	int no_truck = limit_w;	//�ٸ��� �ƹ��͵� ���� �� ��ƿ �� �ִ� ����. 
	
	queue<int> truck;	//�Է¹��� Ʈ�� ���Ը� ť �����̳ʿ� ���ʷ� ���� 
	for(int i=0; i<truck_w.size(); ++i)
		truck.push(truck_w[i]);

	vector<int> bridge(leng);	//�ٸ� ���� ����, �ʱ�ȭ ���´� ��� 0����. 
	
//	//������� ù��° Ʈ�� ���
//	cout<<truck.front()<<"		";
//	//�ٸ� ����, �ٸ��Ѱ�, �ð� ���
//	for(int i=leng-1; i>=0; --i)
//		cout<<bridge[i]<<' ';
//	cout<<"		"<<limit_w<<"		"<<total_time<<endl; 
	
	while(!truck.empty()){	//��� Ʈ���� ����������. 
			
		bridge.erase(bridge.begin());				//�� �տ��ִ� �� ����
		
		limit_w = no_truck;				//�ٸ� �Ѱ� ������ ���ϱ� ���� �ٽ� �ʱ�ȭ. 
		for(int i=0; i<bridge.size(); ++i){		//�ٸ��� �ߵ� �� �ִ� ���� ���. 
			limit_w -= bridge[i];
		}

		if(limit_w >= truck.front() && !truck.empty()){		//�ٸ��� ������ ���� Ʈ���� ������, �̸� ��ƿ �� �ִٸ� �ڵ���� 
			bridge.push_back(truck.front());//�ٸ��� ��� Ʈ�� ť�� �ִ� ���� ù��° Ʈ�� ����.
			limit_w -= truck.front();		//������ Ʈ�����Ը�ŭ ���� �Ѱ迡�� ��. 
			truck.pop();					//��� Ʈ�� ť���� ������ Ʈ�� ����.  
		}
		else{	//�ٸ��� ������ ���� Ʈ���� ��ƿ �� ���ٸ� ���� �ڵ� ���� 
			bridge.push_back(0);			//Ʈ���� �������� ���ϹǷ� 0�� �־���.
		}
		total_time++;	//1�� ���� 
		
//		/************************************************************/
//		//������� ù��° Ʈ�� ���
//		cout<<truck.front()<<"		";
//		//�ٸ� ����, �ٸ��Ѱ�, �ð� ���
//		for(int i=leng-1; i>=0; --i)
//			cout<<bridge[i]<<' ';
//		cout<<"		"<<limit_w<<"		"<<total_time<<endl; 
//		/************************************************************/
		
	}
	total_time += leng;
	
	return total_time;
} 

int main(void){
	
	int leng = 2;		 				//�ٸ����� ���� 
	int limit_w = 10;					//�ٸ� �Ѱ� ���� 
	vector<int> truck_w = {7,4,5,6};	//Ʈ�� ���� ���� 
	
	int result;
	result = solution(leng, limit_w, truck_w);
	
	cout<< result <<endl;
	
	
	return 0;
}
