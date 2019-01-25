#include<iostream>
#include<string>
#include<sstream>
#include<fstream>

using namespace std;

typedef struct op{
    string data;
    struct op* next;
}node_op;

typedef struct operand{
    int data;
    struct operand* next;
}node_operand;

node_op* opTop = NULL;
node_operand* operTop = NULL;

void push_operand(int _data){
	node_operand* operNode = new node_operand;
    operNode->data = _data;
    operNode->next = operTop;
    operTop = operNode;
}
void push_op(string _data){
    node_op* opNode = new node_op;
    opNode->data = _data;
    opNode->next = opTop;
    opTop = opNode;
}

int pop_operand(){
    if (operTop == NULL) 
		return -1;
    int data = operTop->data;
    node_operand* operNode = operTop->next;
    delete operTop;
    operTop = operNode;
    return data;
}
string pop_op(){
    if (opTop == NULL) 
		return "";
    string data = opTop->data;
    node_op* opNode = opTop->next;
    delete opTop;
    opTop = opNode;
    return data;
}

int main(void){


	ifstream fin;
	ofstream fout;
	
	fin.open("linkstack.inp");
	fout.open("linkstack.out");

	int result = 0;
	
	int first;
	fin>>first;
	push_operand(first);
	
	stringstream ss;
	ss<<fin.rdbuf();
	
	fin.close();
	
	string s_op;
	string s_operand;
	int num;
	while(!ss.eof()){
		ss>>s_op>>s_operand;
		num = stoi(s_operand);
		
		if(s_op == "*"){
			result = pop_operand();
			result *= num;
			push_operand(result);
		}
		else if(s_op == "/"){
			result = pop_operand();
			result /= num;
			push_operand(result);
		}
		else{
			push_operand(num);
			push_op(s_op);
		}
	}

	
	result = 0;
	int temp=0;
	string op_temp;
	while(true){
		op_temp = pop_op();
		if(op_temp == "+"){
			result += pop_operand();
		}
		else if(op_temp == "-"){
			result += (pop_operand() * -1);
		}
		else{
			break;
		}
		
	}
	
	result += pop_operand();
	fout << result <<endl;
	
    return 0;
}
