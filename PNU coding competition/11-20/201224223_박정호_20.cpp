#include <iostream>
#include <vector>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    
    //�켱������ ���� ���� ���� ã�´�. 
    int high_p=priorities[0];
    for(int i=1; i<priorities.size(); ++i){
		if(high_p < priorities[i])
			high_p = priorities[i];
	}
    //�켱������ ���� ������ ����ϰ�, �ƴϸ� ���� �ڷ� ������.
	int cnt=0; //��� ���� 
    while(priorities.empty() != 1){
    	if(priorities.front() >= high_p){
    		priorities.erase(priorities.begin());
    		cnt++;
    		high_p=priorities[0];
		    for(int i=1; i<priorities.size(); ++i){
				if(high_p < priorities[i])
					high_p = priorities[i];
			}
    	}
    	else{
    		priorities.push_back(priorities.front());
			priorities.erase(priorities.begin());
		}
		
		for(int j=0; j<priorities.size(); ++j)
			cout<<priorities[j]<<' ';
		cout<<endl;
    }
    
    return answer;
}

int main(void){
	
	vector<int> priorities = {1,1,9,1,1,1};
	int location = 0;
	
	int answer = solution(priorities, location);
	
	return 0;
}

