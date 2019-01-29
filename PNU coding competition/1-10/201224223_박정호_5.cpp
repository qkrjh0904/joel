#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 0;

    int row = routes.size();	//���� ���� 
    
    //���� ���� ���� ū �� ���� 
    int _min = routes[0][0];
    int _max = routes[0][0];
    for(int i=0; i<row; ++i){
		for(int j=0; j<2; ++j){
			_min = min(_min, routes[i][j]);
			_max = max(_max, routes[i][j]); 
		}
	}
	
	int num = _max-_min+1;		//�ּڰ����� �ִ񰪱����� ���� ���� 
	vector<int> v(num);			//�ֱ����� ���� ��� ����, 0���� �ʱ�ȭ 
	
	//���� ���� �� ���� ��� �������� �Ǵ��� �ľ� 
	int n=0;
	for(int i=_min; i<=_max; ++i){
		for(int j=0; j<row; ++j){
			if(i >= routes[j][0] && i <= routes[j][1])
				v[n]++;
		}
		n++;
	}
	
	//�������� ���� ū �κ� ã�� 
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

	for(int i=0; i<row; ++i){	//�����տ� ���ϴ� �������� 1, ������ ������ 0���� ����. 
		if(v_max[0] >= routes[i][0] && v_max[0] <= routes[i][1])
			row_num[i]++;
	}
	
	
	vector<vector<int> > new_v;	
	for(int i=0; i<row_num.size(); ++i){
//		cout<<row_num[i]<<' ';
		if(row_num[i] == 0){	//0���� ������ �������� �ٽ� �ݺ���Ű�� ���� ���ο� ���Ϳ� ����. 
			new_v.push_back(routes[i]);	
		}
	}
	
	//ī�޶� �߰� �� ���� ������ �ٽ� ó������ �ݺ�(���) 
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
