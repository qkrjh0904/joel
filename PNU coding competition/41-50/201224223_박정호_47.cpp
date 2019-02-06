#include <iostream>

using namespace std;

int solution(int n) {
    int answer = 1;	//자기자신은 무조건 포함. 
    if(n==1)
		return answer; 
    //두개 이상의 조합으로 나타내기위해서는 절반보다 작아야한다. 
    int sum=0;	//연속된 수의 합 
    int cnt=0;	//몇번째 인지 카운트 
    for(int i=(n/2 + n%2); i>=1; --i){	
		sum += i;	//연속된 수의 합. 
		cout<<i<<endl;
		if(sum == n){	//연속된 수의 합이 n이 되면 
		 	answer++;	//answer 하나 추가. 
		 	cnt++;		//카운트 하나 증가 
		 	i = n/2 + n%2 - cnt +1;	//i를 카운트만큼 뺀부분부터 시작
		 	cout<<"sum = "<<sum<<endl;
		 	sum=0;		//sum 초기화 
		 }
		else if(sum > n){
			cout<<"sum = "<<sum<<endl;
			cnt++;	//카운트 하나 증가 
			sum=0;	//sum 초기화 
			i = n/2 + n%2 - cnt+1;	//i를 카운트만큼 뺀부분부터 시작
			
		}
		
	}
    
    return answer;
}

int main(void){
	
	int n = 15;
	int answer = solution(n);
	cout<< answer <<endl;

	return 0;
} 
