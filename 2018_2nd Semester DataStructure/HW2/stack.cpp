#include <iostream>
#include <string>
#include <stack>
#include <fstream>

using namespace std;

int main(void)
{
	ifstream fin;
	ofstream fout;

	fin.open("stack.inp");
	fout.open("stack.out");
		
		
	string eq;
	getline(fin, eq);

	string snum="";
	int n;

	stack<int> num;
	stack<string> op;
	
	int temp=0;	
	for(int i=0; i<eq.size(); ++i){
		if(eq[i] == ' ' && snum != ""){
			n = stoi(snum);
			num.push(n);
			snum = "";
			if(!op.empty()){
				if(op.top() == "*"){
					int b = num.top();
					num.pop();
					int a = num.top();
					num.pop();
					temp = a*b;
					num.push(temp);
					
					op.pop();
				}
				else if(op.top() == "/"){
					int b = num.top();
					num.pop();
					int a = num.top();
					num.pop();
					temp = a/b;
					num.push(temp);
					
					op.pop();
				}
			}
		}
		else if(eq[i] == '+'){
			op.push("+");
		}
		else if(eq[i] == '-'){
			op.push("-");
		}
		else if(eq[i] == '*'){
			op.push("*");
		}
		else if(eq[i] == '/'){
			op.push("/");
		}
		else if(eq[i] != ' '){
			snum += eq[i];
			if(i == eq.size()-1){
				n = stoi(snum);
				num.push(n);
			}
		}
	}

	
//	int numsize = num.size();
//	for(int i=0; i<numsize; ++i){
//		cout<<num.top()<<' ';
//		num.pop();
//	}
//	cout<<endl;
//	int opsize = op.size();
//	for(int i=0; i<opsize; ++i){
//		cout<<op.top()<<' ';
//		op.pop();
//	}
//	cout<<endl;
	
	int temp1 = num.top();
	num.pop();
	int result = 0;	
	int opsize = op.size();
	
	for(int i=0; i<opsize; ++i){		
		if(op.top() == "+"){
			op.pop();
		}
		else if(op.top() =="-"){
			temp1 *= -1;
			op.pop();
		}
		result += temp1;
		temp1 = num.top();
		num.pop();
	}
	result += temp1;
	fout<<result<<endl;
	cout<<result<<endl;
	
	fin.close();
	fout.close();

	return 0;
}
