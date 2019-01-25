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
	
	fin.open("linkstack.inp");
	
	stringstream ss;
	ss<<fin.rdbuf();
	
	fin.close();
	
	string op;
	string operand;
	
	while(!ss.eof()){
		ss>>op>>operand;
		cout<<op<<' '<<operand<<endl;
		
	}

	string a= "123";
	int b = stoi(a);
	cout<<b+1<<endl;
    return 0;
}
