#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> weight) {
    int answer = 1;		//측정가능한 가장 작은수인 1부터 시작.
	
	sort(weight.begin(), weight.end());	//순서대로 정렬. 
//	for(int i=0; i<weight.size(); ++i)
//		cout<< weight[i] << ' ';
//	cout<<endl;

    int max=0;	//잴 수 있는 가장 큰 값. 
    for(int i=0; i<weight.size(); ++i)
    	max += weight[i];
    
	//가장 작은 1부터 max이전까지 반복하여 찾기.	
    for(int i=1; i<max; ++i){
		
	}
    
    
    return answer;
}

int main(void){

	vector<int> weight = {3,1,6,2,7,30,1};
	int answer = solution(weight);
	cout<< answer <<endl;
	
	return 0;
}
