#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

bool compare(const pair<double, int> &a, const pair<double, int> &b){
    if(a.first == b.first)
        return a.second < b.second;
    return a.first > b.first;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer(N);
    vector<int> arrive(N+2);
    vector<int> fail(N+2);
    
    for(int i=1; i<N+2; ++i)
        arrive[i] = stages.size();
    for(int i=0; i<stages.size(); ++i){
        //스테이지에 도달하지 못한사람을 전체 사람에서 뺀다.
        for(int j=stages[i]+1; j<N+2; ++j){
            arrive[j]--;
        }
        //스테이지에 있는사람은 아직 클리어를 못했으니 실패한사람에 추가
        fail[stages[i]]++;
    }
    /*도달한 사람 수 출력*/
    // for(int i=1; i<arrive.size(); ++i)
    //     cout<<arrive[i]<<' ';
    // cout<<endl;
    /*실패한 사람 수 출력*/
    // for(int i=1; i<fail.size(); ++i)
    //     cout<<fail[i]<<' ';
    // cout<<endl;
    
    //실패율 구하기.
    vector<double> failure(N+2);
    for(int i=1; i<N+1; ++i){
        failure[i] = (double)fail[i]/arrive[i];
    }
    /*실패율 출력*/
    // for(int i=1; i<failure.size(); ++i)
    //     cout<<failure[i]<<' ';
    // cout<<endl;
    
    //실패율과, 스테이지를 해시테이블 생성
    vector<pair<double, int>> rank(N+1);
    for(int i=1; i<N+1; ++i){
        rank[i] = make_pair(failure[i], i);
    }
    //실패율대로 sorting
    sort(rank.begin()+1, rank.end(), compare);
    /*rank 출력*/
    for(int i=1; i<rank.size(); ++i){
        cout<<rank[i].first<<' '<<rank[i].second<<'\n';
    }
    //정답 입력
    for(int i=1; i<rank.size(); ++i){
        answer[i-1] = (rank[i].second);
    }
    
    return answer;
}
