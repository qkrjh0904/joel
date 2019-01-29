#include <iostream>
#include <vector> 

using namespace std;

int solution(vector<int> left, vector<int> right) {
    int answer = 0;
    
    int left_max = left[0];
    int right_max = right[0];
    
    //좌측과 우측의 카드의 최댓값을 찾는다. 
    for(int i=1; i<left.size(); ++i){
		if(left_max < left[i])
			left_max = left[i];
		if(right_max < right[i])
			right_max = right[i];
	}
	
	//좌측의 최댓값이 우측보다 클경우 우측의 모든카드는 점수를 얻을 수 있다. 
	if(left_max > right_max){
		for(int i=0; i<right.size(); ++i)
			answer += right[i];
		return answer;
	}
	
	//우측의 최댓값이 더 큰경우.
    if(left.front() > right.front()){	//왼쪽카드가 더 큰 경우 오른쪽 카드를 버리며 점수를 올린다. 
		score += right.front();
		right.erase(right.begin());
	}
    
    
    
    
//    //두 카드가 모두 소진될때까지 진행. 
//    while(left.size()!=0 || right.size()!=0){
//    	if(left.front() > right.front()){	//왼쪽카드가 더 큰 경우 오른쪽 카드를 버리며 점수를 올린다. 
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
