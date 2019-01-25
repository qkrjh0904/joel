#include <iostream>
#include <fstream>
#include <stdio.h>

#define INF 9999		//max weight 

using namespace std;

int main(void){
	ifstream fin;
	ofstream fout;
	fin.open("graph.inp");
	fout.open("graph.out");
	int answer=1;
	
	int node_num=0;
	int edge_num=0;
	fin >> node_num >> edge_num;
	
	int adj[node_num][node_num];	//adj matrix
	
	//reset the matrix
	for(int i=0; i<node_num; ++i){
		for(int j=0; j<node_num; ++j){
			if(i==j){
				adj[i][j]=0;
				continue;
			}
			adj[i][j]=INF;
		}
	}

	int src_node;
	int dest_node;
	int weight;
	for(int i=0; i<edge_num; ++i){
		fin >> src_node >> dest_node >> weight;
		adj[src_node-1][dest_node-1] = weight;
		adj[dest_node-1][src_node-1] = weight;
	}
	
//	for(int i=0; i<node_num; ++i){
//		for(int j=0; j<node_num; ++j)
//			printf("%4d ",adj[i][j]);
//		cout<<endl;
//	}

	//Floyd algorithm.
	for(int k=0; k<node_num; ++k){
		for(int i=0; i<node_num; ++i){
			for(int j=0; j<node_num; ++j){
				if(adj[i][k]+adj[k][j] < adj[i][j])
					adj[i][j] = adj[i][k]+adj[k][j];
			}
		}
	}
	
//	cout<<endl;
	
//	for(int i=0; i<node_num; ++i){
//		for(int j=0; j<node_num; ++j)
//			printf("%4d ",adj[i][j]);
//		cout<<endl;
//	}
	
	int sum[node_num] = {0,};
	int temp=0;
	for(int i=0; i<node_num; ++i){
		for(int j=0; j<node_num; ++j){
			temp += adj[i][j];
		}
		sum[i] = temp;
		temp=0;
	}
	
//	cout<<endl;
//	for(int i=0; i<node_num; ++i)
//		cout<<sum[i]<<' ';
	int min = sum[0];
	int min_node=0;
	for(int i=0; i<node_num; ++i){
		if(min > sum[i]){
			min = sum[i];
			min_node = i;
		}
	}
	answer = min_node+1;
//	cout<<endl;
//	cout<<min<<' '<<answer<<endl;
	
	fout<<answer<<endl;
	fin.close();
	fout.close();
	
	return 0;
}
