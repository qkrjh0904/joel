#include<iostream>
#include<fstream>
using namespace std;
int main(void)
{
	int a;
	int sum=0;
	
	ifstream ifs("input.txt");
	if(!ifs.is_open()){
		cerr<<"Input File Error" << endl;
		return -1;
	}
	while(ifs>>a){
		sum += a;
	}
	ifs.close();
	
	ofstream ofs("output.txt");
	if(!ofs.is_open()){
		cerr << "Output File Error" << endl;
		return -1;
	}
	ofs << "sum : " << sum << endl;
	ofs.close();
	return 0;
}
