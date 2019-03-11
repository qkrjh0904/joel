#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

void solution(){
	int n;
	cin>>n;
	vector<string> input(n);
	vector<char> alpha;
	for(int i=0; i<n; ++i)
		cin>>input[i];
	for(int i=0; i<input.size(); ++i){
		for(int j=0; j<input[i].length(); ++j){
			alpha.push_back(input[i][j]);
		}
	}
	sort(alpha.begin(), alpha.end());
	alpha.erase(unique(alpha.begin(), alpha.end()), alpha.end());
	int size = alpha.size();
	vector<int> key(size);
	int number=9;
	for(int i=0; i<size; ++i){
		key[i] = number--;
	}
	
	int answer=0;
	do{
		int temp=0;
		for(int i=0; i<input.size(); ++i){
			int times=1;
			
			for(int j=input[i].size()-1; j>=0; --j){
				for(int k=0; k<alpha.size(); ++k){
					if(input[i][j]==alpha[k]){
						temp += key[k]*times;
						break;
					}
				}
				times*=10;
			}
		}
		answer = max(answer, temp);
		
	}while(prev_permutation(key.begin(), key.end()));
	cout<<answer<<endl;
}

int main(){
	solution();
	return 0;
}
