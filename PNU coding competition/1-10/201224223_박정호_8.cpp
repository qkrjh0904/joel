#include <iostream>
#include <vector> 

using namespace std;

int solution(vector<int> left, vector<int> right) {
    int answer = 0;
    
    int left_max = left[0];
    int right_max = right[0];
    
    //������ ������ ī���� �ִ��� ã�´�. 
    for(int i=1; i<left.size(); ++i){
		if(left_max < left[i])
			left_max = left[i];
		if(right_max < right[i])
			right_max = right[i];
	}
	
	//������ �ִ��� �������� Ŭ��� ������ ���ī��� ������ ���� �� �ִ�. 
	if(left_max > right_max){
		for(int i=0; i<right.size(); ++i)
			answer += right[i];
		return answer;
	}
	
	//������ �ִ��� �� ū���.
    if(left.front() > right.front()){	//����ī�尡 �� ū ��� ������ ī�带 ������ ������ �ø���. 
		score += right.front();
		right.erase(right.begin());
	}
    
    
    
    
//    //�� ī�尡 ��� �����ɶ����� ����. 
//    while(left.size()!=0 || right.size()!=0){
//    	if(left.front() > right.front()){	//����ī�尡 �� ū ��� ������ ī�带 ������ ������ �ø���. 
//			score += right.front();
//			right.erase(right.begin());
//		}
//    		
//	}
    
    
    return answer;
}

int main(void){
	
	vector<int> left = {3,2,5};
	vector<int> right = {2,4,1};
	
	int answer = solution(left, right);
	cout<< answer << endl;
	
	return 0;
}
