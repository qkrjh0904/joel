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
	cout<< node_name << "��� ����"<<endl; 
}

void add_data(string node_name, int data){
	cout<< node_name << "��忡 " << data << "����"<<endl; 
}

int main(void){


	ifstream fin;
	ofstream fout;
	
	fin.open("3.inp");
	
	int node_num=0;
	fin>>node_num;
	
	//node a ���� �� data ���� , ���� node ���� n �Է¹ޱ� 
	string node_name;
	string sub_node_name;
	int data;
	int n; 
	
	fin>> node_name >> data >> n;
	add_node(node_name);
	add_data(node_name, data);

	//n���� node ����, node name�� �ڿ� �Է¹������.
	for(int i=0; i<n; ++i){
		//node����
		fin>>sub_node_name;
		add_node(sub_node_name);	
	} 
	
	//�Է¹��� node��  data ����
	for(int i=1; i<node_num; ++i){
		fin >> node_name >> data >> n;
		//node_name�� data ����
		add_data(node_name, data);

		for(int j=0; j<n; ++j){
			//node ���� 
			fin >> sub_node_name;
			add_node(sub_node_name);
		} 
	} 

	fin.close();

    return 0;
}
