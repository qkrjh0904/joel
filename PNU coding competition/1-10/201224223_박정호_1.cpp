#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answer){
	
	vector<int> ans1 = {1, 2, 3, 4, 5};					//1�� �����ڰ� ��� ��� 
	vector<int> ans2 = {2, 1, 2, 3, 2, 4, 2, 5};		//2�� �����ڰ� ��� ��� 
	vector<int> ans3 = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};	//3�� �����ڰ� ��� ��� 
	
	vector<int> winner;	//���� ���� ���� ����� ����ϴ� �����̳� 
	
	vector<int> score = {0,0,0};	//���� ���� ���� �� �ʱ�ȭ 
	
	
	for(int i=0; i<answer.size(); ++i){	//������ ������ŭ �ݺ��ؼ� ���� Ȯ�� 
	
		//�����ڵ��� ���� ��� ����� ��ġ�ϸ� 1�� �߰� 
		if(answer[i] == ans1[i%5]) 	//1�� �����ڴ� 5���� ��Ģ���� �ݺ� 
			score[0]++;
		if(answer[i] == ans2[i%8])	//2�� �����ڴ� 8���� ��Ģ���� �ݺ� 
			score[1]++;
		if(answer[i] == ans3[i%10])	//3�� �����ڴ� 10���� ��Ģ���� �ݺ� 
			score[2]++;
	}

//	cout << "������ 1�� " << score[0] << "������ ������ϴ�." << endl;
//	cout << "������ 2�� " << score[1] << "������ ������ϴ�." << endl;
//	cout << "������ 3�� " << score[2] << "������ ������ϴ�." << endl;
	
	//���� ���� ���� ����. 
	int max_score = max(max(score[0], score[1]), score[2]);
	
	for(int i=0; i<3; ++i){
		if(score[i] == max_score)
			winner.push_back(i+1);
	}
	
	return winner;
	
}

int main(void){

	vector<int> answer = {1,2,3,4,5};	//���� ���� 
	
	vector<int> winner;
	winner = solution(answer);
	
//	cout<<"���� ���� ���� ������ ���� ����� ������ ";
	for(int i=0; i<winner.size(); ++i)
		cout<< winner[i] <<endl;
//	cout<<" �Դϴ�."<<endl;
	
	
	return 0;
}
