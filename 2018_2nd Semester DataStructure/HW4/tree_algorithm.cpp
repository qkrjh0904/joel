#include<iostream>
#include<string>
#include<sstream>
#include<fstream>
#include<vector>

using namespace std;

int search(void){
	int total_cost=0;
	
	return total_cost;
}

void add_node(string node_name){
	cout<< node_name << "노드 생성"<<endl; 
}

void add_data(string node_name, int data){
	cout<< node_name << "노드에 " << data << "저장"<<endl; 
}

int main(void){


	ifstream fin;
	ofstream fout;
	
	fin.open("3.inp");
	
	int node_num=0;
	fin>>node_num;
	
	//node a 생성 후 data 저장 , 하위 node 개수 n 입력받기 
	string node_name;
	string sub_node_name;
	int data;
	int n; 
	
	fin>> node_name >> data >> n;
	add_node(node_name);
	add_data(node_name, data);

	//n개의 node 생성, node name은 뒤에 입력받은대로.
	for(int i=0; i<n; ++i){
		//node생성
		fin>>sub_node_name;
		add_node(sub_node_name);	
	} 
	
	//입력받은 node에  data 저장
	for(int i=1; i<node_num; ++i){
		fin >> node_name >> data >> n;
		//node_name에 data 저장
		add_data(node_name, data);

		for(int j=0; j<n; ++j){
			//node 생성 
			fin >> sub_node_name;
			add_node(sub_node_name);
		} 
	} 

	fin.close();

    return 0;
}
