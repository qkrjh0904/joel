#include<iostream>
#include<string>
#include<sstream>
#include<fstream>
#include<vector>

using namespace std;

class Node{
public:
	string node_name;
	int data;
	Node* child[30];
	
	Node(){
		node_name = "";
		data = 0;
		for(int i=0; i<30; ++i)
			child[i] = NULL;
	}
	~Node(){}
	void setName(string s){ node_name = s; }
	void setData(int x){ data = x; }
	int getData(){ return data; }
	string getName(){ return node_name; }
	
};

int search(Node* node){
	int cnt=0;
	int result=0;
	for(int i=0; i<30; ++i){
		if(node->child[i] == NULL)
			cnt++;
		else
			result += search(node->child[i]);
			
		if(cnt==30)
			return node->data;
		else if(i==29){
			result += node->data;
			if(node->node_name == node[0].node_name)
				return result;
			return node->data;
		}
	}
	
}

int main(void){
	
	ifstream fin;
	ofstream fout;
	fin.open("tree.inp");
	fout.open("tree.out");
	int result=0;

	//node constructor
	int node_num=0;
	fin>>node_num; 
	Node node[node_num];
	
	string node_name;
	string sub_node_name;
	int data;
	int sub_node_num;
	int stack_node = 1;
	int node_n = 0;
	
	fin>> node_name >> data >> sub_node_num;
	
	node[node_n].setName(node_name);
	node[node_n].setData(data);
	for(int i=0; i<sub_node_num; ++i){
		//set node info
		fin>>sub_node_name;
		node[node_n+(i+1)].setName(sub_node_name);
		node[node_n].child[i] = &node[node_n+(i+1)];
	}
	stack_node += sub_node_num;
	

	for(int i=1; i<node_num; ++i){
		fin >> node_name >> data >> sub_node_num;
		//save data at node_name
		node_n = i;
		node[node_n].setData(data);

		for(int j=0; j<sub_node_num; ++j){
			//set node info
			fin >> sub_node_name;
			node[stack_node+j].setName(sub_node_name);
			node[node_n].child[j] = &node[stack_node+j];
		} 
		stack_node += sub_node_num;
	}

	result = search(node);
	fout << result << endl;
	
	fin.close();
	fout.close();
	
	return 0;

}
