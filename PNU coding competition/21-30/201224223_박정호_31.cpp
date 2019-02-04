#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    
    sort(people.begin(), people.end());	//���� ����
//    cout<<"��Ʈ �� :"<<answer<<endl;
//    for(int i=0; i<people.size(); ++i)
//    	cout<< people[i] << ' ';
//    cout<< endl;
    
    
    while(people.size() > 0){	//��� ����� �ǳʰ��� ���� �ݺ�. 
    	//���� ��� ���� 1���̸� ��Ʈ�� �ϳ� ������Ű�� ��������. 
    	if(people.size() == 1)
			return ++answer;
 		//���� ���� ���Կ� ���� ū������ ���� limit���� ũ�� ���� ū ���Դ� ȥ�� Ÿ���Ѵ�.
	    if(people[0] + people[people.size()-1] > limit){
//			cout<<"������ ��� : "; 	 
//	    	cout<< people[people.size()-1] << endl;
			people.pop_back();	//���� ���ſ� ����� ���� 
			answer++;			//��Ʈ���� �߰� 
//			cout<<"��Ʈ �� :"<<answer<<endl;
//			for(int i=0; i<people.size(); ++i)
//	    		cout<< people[i] << ' ';
//	    	cout<< endl;
		}
		else{	//���� ���ص� �Ѱ躸�� ������� �¿� ������. 
//			cout<<"������ ��� : "; 
//			cout<<people[0]<<' '<<people[people.size()-1]<<endl;
			people.erase(people.begin());
			people.pop_back();
			answer++;
//			cout<<"��Ʈ �� :"<<answer<<endl;
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
