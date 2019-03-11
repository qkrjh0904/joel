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

void sol(){
	int n;
	cin>>n;
	vector<string> input(n);
	vector<int> input_length(n);
	vector<pair<char, int>> map;
	int total=0;
	for(int i=0; i<n; ++i){
		cin>>input[i];
		input_length[i] = input[i].length();
		total += input_length[i];
	}
	int number=9;
	while(total!=0){
		int big = input_length[0];
		int cnt=0;
		for(int i=0; i<input_length.size(); ++i){
			if( big<input_length[i] ){
				big = input_length[i];
				cnt = i;
			}
		}
		
//		cout<<"big : "<<big<<" cnt : "<<cnt<<endl;
//		cout<<input[cnt].length()-input_length[cnt]<<endl;
		bool set=true;
		for(int i=0; i<map.size(); ++i){
			if(map[i].first == input[cnt][ input[cnt].length()-input_length[cnt] ])
				set = false;
		}
		if(set){
			map.push_back(make_pair(input[cnt][ input[cnt].length()-input_length[cnt] ], number--));
//			cout<<input[cnt][ input[cnt].length()-input_length[cnt] ]<<" enter"<<endl;
		}
		input_length[cnt]--;
		total--;
	}
//	for(int i=0; i<map.size(); ++i){
//		cout<<map[i].first<<' '<<map[i].second<<'\n';
//	}
	
	int answer=0;
	for(int i=0; i<input.size(); ++i){
		int leng = input[i].length();
		int times=1;
		for(int j=leng-1; j>=0; --j){
			for(int k=0; k<map.size(); ++k){
				if( map[k].first==input[i][j] ){
					answer += map[k].second*times;
					break;
				}
			}
			times *= 10;
		}
	}
	cout<<answer<<endl;
	
}
int main(){
	solution();
	return 0;
}
