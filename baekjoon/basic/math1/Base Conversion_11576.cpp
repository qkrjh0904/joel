#include <iostream>
#include <vector>

using namespace std;

int toTen(vector<int> v, int A){
	int answer=0;
	
	int temp=1;
	for(int i=v.size()-1; i>=0; --i){
		answer += v[i]*temp;
		temp *= A;
	}
	
	return answer;
}

vector<int> toB(int ten, int B){
	vector<int> answer;
	for(int i=ten; i>0; ){
		answer.push_back(i%B);
		i /= B;
	}
	
	return answer;
}

void answer(void){
	int A, B;
	int m;
	cin>>A>>B;
	cin>>m;
	
	int n;
	vector<int> A_num;
	for(int i=0; i<m; ++i){
		cin>>n;
		A_num.push_back(n);
	}
	
	int AtoTen = toTen(A_num, A);
	vector<int> answer = toB(AtoTen, B);
	for(int i=answer.size()-1; i>=0; --i){
		cout<<answer[i]<<' ';
	}
	
}

int main(){
	answer();
	return 0;
}
