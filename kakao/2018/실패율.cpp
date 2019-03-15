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
        //���������� �������� ���ѻ���� ��ü ������� ����.
        for(int j=stages[i]+1; j<N+2; ++j){
            arrive[j]--;
        }
        //���������� �ִ»���� ���� Ŭ��� �������� �����ѻ���� �߰�
        fail[stages[i]]++;
    }
    /*������ ��� �� ���*/
    // for(int i=1; i<arrive.size(); ++i)
    //     cout<<arrive[i]<<' ';
    // cout<<endl;
    /*������ ��� �� ���*/
    // for(int i=1; i<fail.size(); ++i)
    //     cout<<fail[i]<<' ';
    // cout<<endl;
    
    //������ ���ϱ�.
    vector<double> failure(N+2);
    for(int i=1; i<N+1; ++i){
        failure[i] = (double)fail[i]/arrive[i];
    }
    /*������ ���*/
    // for(int i=1; i<failure.size(); ++i)
    //     cout<<failure[i]<<' ';
    // cout<<endl;
    
    //��������, ���������� �ؽ����̺� ����
    vector<pair<double, int>> rank(N+1);
    for(int i=1; i<N+1; ++i){
        rank[i] = make_pair(failure[i], i);
    }
    //��������� sorting
    sort(rank.begin()+1, rank.end(), compare);
    /*rank ���*/
    for(int i=1; i<rank.size(); ++i){
        cout<<rank[i].first<<' '<<rank[i].second<<'\n';
    }
    //���� �Է�
    for(int i=1; i<rank.size(); ++i){
        answer[i-1] = (rank[i].second);
    }
    
    return answer;
}
