#include <iostream>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    //길이가 n일때, 시작을 두가지의 경우로 할 수 있다.
	//처음을 가로가 1인 직사각형 하나로 시작하거나, 가로가 2인 직사각형 두개로 시작하거나 이다.
	//가로가 1인 직사각형으로 시작하면, 길이가 n-1일때의 경우의 수와 같고,
	//가로가 2인 직사각형 2개로 시작하면, 길이가 n-2일때의 경우의 수와 같다.
	
	vector<int> v = {1, 2};	//길이가 1, 2일때 각각 1,2가지 방법이 있다.
	for(int i=2; i<n; ++i){
		v.push_back(v[i-1] + v[i-2]);	//전, 전전 경우의수를 더한값을 벡터에 넣는다. 
	} 

//	for(int i=0; i<v.size(); ++i)
//		cout<< v[i] << ' ';
//	cout<<endl;
	
	answer = v[n-1]%1000000007;	//마지막 값이 answer가 된다. 
    
    return answer;
}

int main(void){
	int n = 5000;
	int answer = solution(n);
	cout<<answer<<endl;

	return 0;
}
