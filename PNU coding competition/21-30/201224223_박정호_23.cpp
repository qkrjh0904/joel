#include <iostream>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    //���̰� n�϶�, ������ �ΰ����� ���� �� �� �ִ�.
	//ó���� ���ΰ� 1�� ���簢�� �ϳ��� �����ϰų�, ���ΰ� 2�� ���簢�� �ΰ��� �����ϰų� �̴�.
	//���ΰ� 1�� ���簢������ �����ϸ�, ���̰� n-1�϶��� ����� ���� ����,
	//���ΰ� 2�� ���簢�� 2���� �����ϸ�, ���̰� n-2�϶��� ����� ���� ����.
	
	vector<int> v = {1, 2};	//���̰� 1, 2�϶� ���� 1,2���� ����� �ִ�.
	for(int i=2; i<n; ++i){
		v.push_back(v[i-1] + v[i-2]);	//��, ���� ����Ǽ��� ���Ѱ��� ���Ϳ� �ִ´�. 
	} 

//	for(int i=0; i<v.size(); ++i)
//		cout<< v[i] << ' ';
//	cout<<endl;
	
	answer = v[n-1]%1000000007;	//������ ���� answer�� �ȴ�. 
    
    return answer;
}

int main(void){
	int n = 5000;
	int answer = solution(n);
	cout<<answer<<endl;

	return 0;
}
