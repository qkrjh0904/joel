 #include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <algorithm>
#include <cmath>

using namespace std;

void solution(){
	int n;
	cin>>n;
	vector<vector<int>> v(n, vector<int>(n));
	for(int i=0; i<n; ++i){
		for(int j=0; j<n; ++j){
			cin>>v[i][j];
		}
	}

	vector<int> team(n);
	for(int i=n/2; i<n; ++i)
		team[i] = 1;
	
	int answer = 1000000;
	
	do{
		vector<int> team_a;
		vector<int> team_b;
		int score_a=0;
		int score_b=0;
		for(int i=1; i<=n; ++i){
			if(team[i-1]==0)
				team_a.push_back(i);
			else
				team_b.push_back(i);
		}
		
		for(int i=0; i<team_a.size()-1; ++i){
			for(int j=i+1; j<team_a.size(); ++j){
				score_a += (v[team_a[i]-1][team_a[j]-1] + v[team_a[j]-1][team_a[i]-1]);
				score_b += (v[team_b[i]-1][team_b[j]-1] + v[team_b[j]-1][team_b[i]-1]);
			}
		}
		int temp = abs(score_a-score_b);
		answer = min(answer, temp);
	}while(next_permutation(team.begin(), team.end())); 
	
	cout<<answer<<'\n';
}

int main(){
	solution();
	return 0;
}
