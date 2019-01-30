#include <iostream>
#include <vector> 

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    vector<int> day(progresses.size());
    for(int i=0; i<progresses.size(); ++i){
		day[i] = (100 - progresses[i])/speeds[i];	//���� �۾������� �ӵ��� ���� �ɸ��� �ϼ��� ���. 
		if((100 - progresses[i])%speeds[i] != 0)	//���� ���ڶ��ٸ� �Ϸ縦 �� �� ä���. 
			day[i]++;
	}
	
	//��� ������ ���� ��¥ ������ �����ش�.
	//������� 3,1,4���� �ɸ��� �ι�° ����� ù��° �����Ͽ� ������ϹǷ� 3,3,4�Ϸ� �����ش�. 
	for(int i=1; i<day.size(); ++i){
		if(day[i] < day[i-1])
			day[i] = day[i-1];
	}
	
	//�� �����ϸ��� ��� ����� �����Ǵ��� ����Ѵ�. 
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
