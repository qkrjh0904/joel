#include <iostream>
#include <string>
#include <stack>

using namespace std;

int solution(string arrangement) {
    int answer = 0;
    
    //��ȣ�� ������ ���� ����. 
    stack<char> s;
    
    for(int i=0; i<arrangement.size(); ++i){	//�Է¹��� string ũ�⸸ŭ �ݺ� 
    	if(arrangement[i] == '('){				//'('�̸� ���ÿ� ����. 
			s.push('(');						
		}
		else if(arrangement[i-1] == '(' && arrangement[i] == ')'){		//')'�̸� ����� '('�� ������. 
			s.pop();			
			answer += s.size();		//'('���� �ٷ�')'�� ������ �������̱� ������ ������ ���� �踷�븸ŭ ������ ����. 
		}
		else if(arrangement[i-1] == ')' && arrangement[i] == ')'){		//')'�̸� ����� '('�� ������. 
			s.pop();			
			answer += 1;		//')'������ �� ')'�� ����, ������ �ִ� �踷����� ���Ḧ ���ϹǷ� 1�� �����ش�. 
		}
		
	}
    return answer;
}

int main(void){
	
	string arrangement = "()(((()())(())()))(())";
	
	int answer = solution(arrangement);
	cout<< answer <<endl;
	
	
	return 0;
}
