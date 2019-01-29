#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 0;

    int row = routes.size();	//행의 갯수 
    
    //가장 작은 수와 큰 수 구별 
    int _min = routes[0][0];
    int _max = routes[0][0];
    for(int i=0; i<row; ++i){
		for(int j=0; j<2; ++j){
			_min = min(_min, routes[i][j]);
			_max = max(_max, routes[i][j]); 
		}
	}
	
	int num = _max-_min+1;		//최솟값에서 최댓값까지의 숫자 개수 
	vector<int> v(num);			//최교집합 갯수 담는 벡터, 0으로 초기화 
	
	//가장 작은 수 부터 몇개의 교집합이 되는지 파악 
	int n=0;
	for(int i=_min; i<=_max; ++i){
		for(int j=0; j<row; ++j){
			if(i >= routes[j][0] && i <= routes[j][1])
				v[n]++;
		}
		n++;
	}
	
	//교집합이 가장 큰 부분 찾기 
	vector<int> v_max(2);
    for(int i=0; i<num; ++i){
//    	cout << i+_min <<" : "<<v[i]<<endl;
    	if(v_max[1] < v[i]){
    		v_max[1] = v[i];
    		v_max[0] = i+_min;
    	}
    }
    cout<<v_max[0]<<' '<<v_max[1]<<endl;
	
	vector<int> row_num(row);

	for(int i=0; i<row; ++i){	//교집합에 속하는 차량들은 1, 속하지 않으면 0으로 설정. 
		if(v_max[0] >= routes[i][0] && v_max[0] <= routes[i][1])
			row_num[i]++;
	}
	
	
	vector<vector<int> > new_v;	
	for(int i=0; i<row_num.size(); ++i){
//		cout<<row_num[i]<<' ';
		if(row_num[i] == 0){	//0으로 설정된 차량들을 다시 반복시키기 위해 새로운 벡터에 삽입. 
			new_v.push_back(routes[i]);	
		}
	}
	
	//카메라 추가 후 남은 차량중 다시 처음부터 반복(재귀) 
	answer++;
	if(new_v.size() != 0)
		answer += solution(new_v);

    return answer;
}

int main(void){
	
	vector<vector<int> > routes = {{-20, 15}, {-14, -5}, {-18, -13}, {-5, -3}};
	
	int answer = solution(routes);
	cout<< answer <<endl;
	
	return 0;
}
