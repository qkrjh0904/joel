#include <iostream>

using namespace std;

int solution(int n) {
    int answer = 1;	//�ڱ��ڽ��� ������ ����. 
    if(n==1)
		return answer; 
    //�ΰ� �̻��� �������� ��Ÿ�������ؼ��� ���ݺ��� �۾ƾ��Ѵ�. 
    int sum=0;	//���ӵ� ���� �� 
    int cnt=0;	//���° ���� ī��Ʈ 
    for(int i=(n/2 + n%2); i>=1; --i){	
		sum += i;	//���ӵ� ���� ��. 
		cout<<i<<endl;
		if(sum == n){	//���ӵ� ���� ���� n�� �Ǹ� 
		 	answer++;	//answer �ϳ� �߰�. 
		 	cnt++;		//ī��Ʈ �ϳ� ���� 
		 	i = n/2 + n%2 - cnt +1;	//i�� ī��Ʈ��ŭ ���κк��� ����
		 	cout<<"sum = "<<sum<<endl;
		 	sum=0;		//sum �ʱ�ȭ 
		 }
		else if(sum > n){
			cout<<"sum = "<<sum<<endl;
			cnt++;	//ī��Ʈ �ϳ� ���� 
			sum=0;	//sum �ʱ�ȭ 
			i = n/2 + n%2 - cnt+1;	//i�� ī��Ʈ��ŭ ���κк��� ����
			
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
