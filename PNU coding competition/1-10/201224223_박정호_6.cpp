#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
	string ans = "";
	
	//참가자와 통과자 알파벳순 정렬 
	sort(participant.begin(), participant.end());
	sort(completion.begin(), completion.end());

	//정확히 sort되었는지 확인. 
//	for(int i=0; i<participant.size(); ++i)
//		cout<<participant[i]<<' ';
//	cout<<endl;
//	for(int i=0; i<completion.size(); ++i)
//		cout<<completion[i]<<' ';
//	cout<<endl;
	
	//참가자 중 한명만 낙오했기 때문에 참가자와 통과자 비교중 다른경우 참가자쪽 명단에 있는 사람이 낙오자다. 
	for(int i=0; i<completion.size(); ++i){		//통과자 명단 수만큼 비교 
		if(participant[i] != completion[i]){	//참가자와 통과자 명단이 다른경우 참가자 명단 return. 
			ans = participant[i];
			return ans;
		}
	}
	//통과자 명단을 다 돌려도 return되지 않았다면, 참가자 명단중 마지막에 있는 사람이다. 
	ans = participant[participant.size()-1];	
    return ans;
}

int main(void){
	
	vector<string> participant = {"leo", "kiki", "eden"};
	vector<string> completion = {"eden", "kiki"};
	
	string ans = solution(participant, completion);
	cout<< ans <<endl;

	return 0;
}
