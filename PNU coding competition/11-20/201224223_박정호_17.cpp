#include <iostream>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr){
    vector<int> answer;
	
	for(int i=1; i<arr.size(); ++i){
		if(arr[i] == arr[i-1]){
			arr.erase(arr.begin()+i);
			i--;
		}
	}
	answer = arr;
    return answer;
}

int main(void){
	
	vector<int> arr = {1,1,1,2,2,2,3,3,3};
	
	vector<int> answer = solution(arr);
	for(int i=0; i<answer.size(); ++i)
		cout<<answer[i]<<' ';
	cout<<endl;
	
	return 0;
}
