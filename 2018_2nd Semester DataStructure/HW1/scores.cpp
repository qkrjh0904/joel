#include<iostream>
#include<vector>
#include<algorithm>
#include<fstream>

using namespace std;

int main(void){
	
	ifstream fin;
	ofstream fout;
	
	fin.open("scores.inp");
	fout.open("scores.out");

	
	int stu_num=0;
	int sub_num=0;
	int sub=0;
	int temp;
	
	fin>>stu_num;
	fin>>sub_num;
	fin>>sub;
	
	vector< vector<int> > v(stu_num, vector<int>(sub_num+1));
	vector< vector<int> > rank(stu_num, vector<int>(sub_num+1));
	
	
	int data;
	
	for(int i=0; i<stu_num; ++i){
		for(int j=0; j<=sub_num; ++j){
			fin>>data;
			v[i][j] = data;
		}
	}
	
//	for(int i=0; i<stu_num; ++i){
//		for(int j=0; j<=sub_num; ++j){
//			cout<<v[i][j]<<' ';
//		}
//		cout<<'\n';
//	}
//	cout<<'\n';
/******************************************/	
/*****************Question 1***************/
/******************************************/
//	cout<<"=====Question #1====="<<'\n';
	//change designated sub with id
	for(int i=0; i<stu_num; ++i){
		temp = v[i][sub];
		v[i][sub] = v[i][0];
		v[i][0] = temp;
	}
	sort(v.begin(), v.end());			//sorting as sub score
	
	for(int i=0; i<stu_num; ++i){
		temp = v[i][sub];
		v[i][sub] = v[i][0];
		v[i][0] = temp;
	}
	
//	for(int i=0; i<stu_num; ++i){
//		for(int j=0; j<=sub_num; ++j){
//			cout<<v[i][j]<<' ';
//		}
//		cout<<'\n';
//	}
//	cout<<'\n';
	//rank of sub
	int rr=0;
	for(int i=stu_num-1; i>=0; --i){
		rank[rr][0] = v[i][0];
		rr += 1;
	}
	//each subject's rank
	int cnt=0;
	for(int i=1; i<=sub_num; ++i){
		for(int j=0; j<stu_num; ++j){
			for(int k=0; k<stu_num; ++k){
				if(v[j][i]<v[k][i])
					cnt++;
			}
			rank[stu_num-1-j][i] = cnt+1;
			cnt=0;
		}
	}
	
	//Q1 output print
	fout<<stu_num<<'\n';
	for(int i=0; i<stu_num; ++i){
		for(int j=0; j<=sub_num; ++j){
			fout<<rank[i][j]<<' ';
		}
		fout<<'\n';
	}

	

/******************************************/
/*****************Question 2***************/
/******************************************/
//	cout<<"=====Question #2====="<<'\n';
	
	sort(rank.begin(), rank.end());
	
	vector<int> count(stu_num);
	
	int top3_cnt=0;
	int top3_num=0;
	for(int i=0; i<stu_num; ++i){
		top3_cnt=0;
		for(int j=1; j<=sub_num; ++j){
			if(rank[i][j]<=3)
				top3_cnt++;
			if(top3_cnt>3){
				top3_num++;
				count[i] += 1;
				break;
			}
		}
	}

	//Q2 output print
	fout<<top3_num<<'\n';
	for(int i=0; i<stu_num; ++i){
		if(count[i]==1){
			for(int j=0; j<=sub_num; ++j){
				fout<<rank[i][j]<<' ';
			}
			fout<<'\n';
		}
	}

/******************************************/
/*****************Question 3***************/
/******************************************/
//	cout<<"=====Question #3====="<<'\n';
	
	int q3_answer = 0;
	int q3_cnt=0;
	for(int i=0; i<stu_num-1; ++i){
		for(int j=i+1; j<stu_num; ++j){
			q3_cnt=0;
			for(int k=1; k<=sub_num; ++k){
				if(rank[i][k]-rank[j][k]>2){
					for(int l=1; l<=sub_num; ++l){
						if((k!=l) && (rank[j][l]-rank[i][l]>10))
							q3_cnt=1;
					}
				}
				if(rank[j][k]-rank[i][k]>2){
					for(int l=1; l<=sub_num; ++l){
						if((k!=l) && (rank[i][l]-rank[j][l]>10))
							q3_cnt=1;
					}
				}
			}
			if(q3_cnt==1)
				q3_answer++;
		}
	}
	
	//Q3 output print
	fout<<q3_answer<<'\n';
	
	
	fin.close();
	fout.close();
		
	return 0;
}
