#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    
    sort(people.begin(), people.end());	//역순 정렬
//    cout<<"보트 수 :"<<answer<<endl;
//    for(int i=0; i<people.size(); ++i)
//    	cout<< people[i] << ' ';
//    cout<< endl;
    
    
    while(people.size() > 0){	//모든 사람이 건너갈때 까지 반복. 
    	//남은 사람 수가 1명이면 보트를 하나 증가시키고 내보낸다. 
    	if(people.size() == 1)
			return ++answer;
 		//가장 작은 무게와 가장 큰무게의 합이 limit보다 크면 가장 큰 무게는 혼자 타야한다.
	    if(people[0] + people[people.size()-1] > limit){
//			cout<<"보내는 사람 : "; 	 
//	    	cout<< people[people.size()-1] << endl;
			people.pop_back();	//가장 무거운 사람을 뺀다 
			answer++;			//보트개수 추가 
//			cout<<"보트 수 :"<<answer<<endl;
//			for(int i=0; i<people.size(); ++i)
//	    		cout<< people[i] << ' ';
//	    	cout<< endl;
		}
		else{	//둘이 합해도 한계보다 적을경우 태워 보낸다. 
//			cout<<"보내는 사람 : "; 
//			cout<<people[0]<<' '<<people[people.size()-1]<<endl;
			people.erase(people.begin());
			people.pop_back();
			answer++;
//			cout<<"보트 수 :"<<answer<<endl;
//			for(int i=0; i<people.size(); ++i)
//	    		cout<< people[i] << ' ';
//	    	cout<< endl;
		}
		
		
	}
	
    return answer;
}

int main(void){
	vector<int> people = {70, 80, 50}; 
	int limit = 100;
	int answer = solution(people, limit);
	cout<<answer<<endl;

	return 0;
}
