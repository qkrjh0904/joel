#include<iostream>

using namespace std;

int main(){
	
	int row=4;
	int col=4;
	
	int mat[row][col];
	for(int i=0; i<row; ++i){
		for(int j=0; j<col; ++j)
			mat[i][j] = 0;
	}
	
	for(int i=0; i<row; ++i){
		for(int j=0; j<col; ++j)
			cout<< mat[i][j]<<' ';
		cout<<endl;
	}

	return 0;
}
