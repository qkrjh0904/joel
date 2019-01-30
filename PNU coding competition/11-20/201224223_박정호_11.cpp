#include <iostream>
#include <vector> 
#include <cmath>

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    
    //��ü �۾������� �߱ٽð��� �� �۾����� ������� ������ �����ش�.
	//��ü �۾��� ���ϱ�.
	int total_works = 0;
	for(int i=0; i<works.size(); ++i)
		total_works += works[i];
		
	//��ü �۾������� �߱ٽð� ����.
	int remain_works = 0;
	remain_works = total_works - n;
	
	//���� �۾����� 0���� �̸� �Ƿε� 0
	if(remain_works <= 0){
		answer = 0;
		return answer;
	}
	
	//���� �۾����� ��ձ��ϱ�.
	int rw_avg = 0;
	rw_avg = remain_works/works.size();
	
	//works�� ��� �۾����� ������� �����ֱ�.
	//�켱������ ���� ū ������. 
	int time = n;
	while(time!=0){
		int max_work = works[0];	//���� ū�� �ʱ�ȭ�� works�� ù��° ���� 
		for(int i=1; i<works.size(); ++i){	//works���� ���� ū �� ã��. 
			if(max_work < works[i])
				max_work = works[i];
		}
		for(int i=0; i<works.size(); ++i){	//works���� ���� ū���� 1�� ����, �ð��� 1�� ����. 
			if(works[i] == max_work){
				works[i]--;
				break;
			}
		}
		time--;
	}

	
	//�߱� ���� �Ƿε� ���.
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
