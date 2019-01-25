#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main(void){
	
	stringstream ss = "I love you";
	
//	ss << cin.rdbuf();
	
	string read;
	while(!ss.eof()){
		ss >> read;
		cout << read << endl;
	}

	return 0;
}
