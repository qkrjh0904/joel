#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<sstream>
#include<fstream>
#include<stack>

using namespace std;



int main(void){


	ifstream fin;
	fin.open("linkstack.txt");
	
	stack<int> operand;
	stack<string> op;
	
	int n_first;
	fin>>n_first;
	operand.push(n_first);
	
	stringstream ss;
	ss<<fin.rdbuf();
	fin.close();
	
	string read;
	
	int cnt=0;
	while(!ss.eof()){
		ss>>read;
		if(cnt==1){
			int n = stoi(read);
			operand.push(n);
			cnt=0;
		}
		else if(cnt==0){
			op.push(read);
			cnt=1;
		}
	}
	int operand_size = operand.size();
	int op_size = op.size();
	
	for(int i=0; i<operand_size; ++i){
		cout<< operand.top() << ' ';
		operand.pop();
	}
	cout<<endl;
	for(int i=0; i<op_size; ++i){
		cout<< op.top() << ' ';
		op.pop();
	}
		
	
	
    return 0;
}
