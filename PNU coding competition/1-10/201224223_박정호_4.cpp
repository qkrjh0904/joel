#include <iostream>
#include <string>
#include <stack>

using namespace std;

int solution(string arrangement) {
    int answer = 0;
    
    //괄호를 저장할 스택 선언. 
    stack<char> s;
    
    for(int i=0; i<arrangement.size(); ++i){	//입력받은 string 크기만큼 반복 
    	if(arrangement[i] == '('){				//'('이면 스택에 저장. 
			s.push('(');						
		}
		else if(arrangement[i-1] == '(' && arrangement[i] == ')'){		//')'이면 저장된 '('를 꺼낸다. 
			s.pop();			
			answer += s.size();		//'('다음 바로')'가 나오면 레이저이기 때문에 이전에 쌓인 쇠막대만큼 조각을 낸다. 
		}
		else if(arrangement[i-1] == ')' && arrangement[i] == ')'){		//')'이면 저장된 '('를 꺼낸다. 
			s.pop();			
			answer += 1;		//')'다음에 또 ')'가 오면, 이전에 있던 쇠막대기의 종료를 뜻하므로 1만 더해준다. 
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
