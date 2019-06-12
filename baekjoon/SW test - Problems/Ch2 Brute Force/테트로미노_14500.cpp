#include <iostream>
#include <vector> 

using namespace std;

int d[500][500];
int tetro[19][4][2] = {
	{{0, 0}, {0, 1}, {0, 2}, {0, 3}},
	{{0, 0}, {1, 0}, {2, 0}, {3, 0}},
	{{0, 0}, {0, 1}, {1, 0}, {1, 1}},
	{{0, 0}, {1, 0}, {1, 1}, {2, 1}},
	{{0, 0}, {0, 1}, {-1, 1}, {-1, 2}},
	{{0, 0}, {1, 0}, {0, 1}, {-1, 1}},
	{{0, 0}, {0, 1}, {1, 1}, {1, 2}},
	{{0, 0}, {0, 1}, {0, 2}, {-1, 1}},
	{{0, 0}, {-1, 1}, {0, 1}, {1, 1}},
	{{0, 0}, {1, 0}, {2, 0}, {1, 1}},
	{{0, 0}, {0, 1}, {0, 2}, {1, 1}},
	{{0, 0}, {1, 0}, {2, 0}, {2, 1}},
	{{0, 0}, {1, 0}, {2, 0}, {2, -1}},
	{{0, 0}, {1, 0}, {0, 1}, {0, 2}},
	{{0, 0}, {0, 1}, {0, 2}, {1, 2}},
	{{0, 0}, {0, 1}, {1, 1}, {2, 1}},
	{{0, 0}, {1, 0}, {2, 0}, {0, 1}},
	{{0, 0}, {1, 0}, {1, 1}, {1, 2}},
	{{0, 0}, {0, 1}, {0, 2}, {-1, 2}}
};
vector<int> sums;
void solution(){
	int n, m;
	cin>>n>>m;
	for(int i=0; i<n; ++i){
		for(int j=0; j<m; ++j){
			cin>>d[i][j];
		}
	}
	
	int sum=0;
	for(int i=0; i<n; ++i){
		for(int j=0; j<m; ++j){
			for(int k=0; k<19; ++k){
				for(int l=0; l<4; ++l){
					if(i+tetro[k][l][0]<0 || i+tetro[k][l][0]>=n || j+tetro[k][l][1]<0 || j+tetro[k][l][1]>=m){
						break;
					}
					sum += d[i+tetro[k][l][0]][j+tetro[k][l][1]];
				}
				sums.push_back(sum);
				sum=0;
			}
		}
	}
	
	int answer=0;
	for(int temp : sums){
		if(answer<temp)
			answer = temp;
	}
	cout<<answer<<'\n';
}

int main(){
	solution();
	return 0;
}
