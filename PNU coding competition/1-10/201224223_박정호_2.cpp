#include <iostream>
#include <string>

using namespace std;

string solution(string s){
	int sleng = s.length();	//�Է� �ܾ� ���� ���� 
	
	while(sleng>2){		//�Է´ܾ 2�ڸ� ���ϸ� �״�� ��ȯ�ϰ�, 2�ڸ����� ũ�� �Ʒ� �ڵ� ���� 
		s.erase(0, 1);			//�Է´ܾ�� ù��° ���� ����. 
		s.erase(sleng-2, 1);	//�Է´ܾ�� ������ ���� ����. 
		
		sleng = s.length();		//�� �� ���� ���� �� �ٽ� ���ڱ��� ����. 
	}
	
	return s;
}

int main(void){
	
	string s = "QWER";	//�Է� �ܾ� ���� 
	
	string result;
	result = solution(s);
	
	cout<< result <<endl;
	
	
	
	return 0;
}
