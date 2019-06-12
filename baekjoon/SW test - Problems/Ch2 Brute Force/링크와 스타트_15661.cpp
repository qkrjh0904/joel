#include <iostream>
#include <vector>

using namespace std;

int team[20][20];
int n;

int go(int index, vector<int> &first, vector<int> &second){
	if(first.size()==n) return -1;
	if(second.size()==n) return -1;
	if(index==n){
		int t1=0, t2=0;
		for(int i=0; i<first.size()-1; ++i){
			for(int j=i+1; j<first.size(); ++j){
				t1 += ( team[first[i]][first[j]] + team[first[j]][first[i]] );
			}
		}
		for(int i=0; i<second.size()-1; ++i){
			for(int j=i+1; j<second.size(); ++j){
				t2 += ( team[second[i]][second[j]] + team[second[j]][second[i]] );
			}
		}
		return t1>t2 ? t1-t2 : t2-t1;
	}
	int ans = -1;
	first.push_back(index);
	int t1 = go(index+1, first, second);
	if(ans==-1 || (t1 != -1 && ans>t1)){
		ans = t1;
	}
	first.pop_back();
	second.push_back(index);
	int t2 = go(index+1, first, second);
	if(ans==-1 || (t2 != -1 && ans>t2)){
		ans = t2;
	}
	second.pop_back();
	return ans;
		
}
void solution(){
	cin>>n;
	for(int i=0; i<n; ++i){
		for(int j=0; j<n; ++j){
			cin>>team[i][j];
		}
	}
	vector<int> first, second;
	cout<< go(0, first, second) << '\n';
}

int main(){
	solution();
	return 0;
}
