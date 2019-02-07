#include <iostream>
#include <vector>

using namespace std;

int solution(int n){
	int answer = 0;
	
	if(n==2){
		cout<< '1' <<endl;
		return 1;
	}
		
	for(int i=n-1; i>=2; --i){
		cout<< i << ' ';
		solution(i);
	}
	cout<<endl;


	return answer;
}

int main(void){
	
	int n = 5;
	int answer = solution(n);
	cout<<answer<<endl;

	
	
	return 0;
}
