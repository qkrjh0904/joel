#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector<pair<string, string> > info;
    vector<pair<char, string> > data;
    
    for(int i=0; i<record.size(); ++i){
        string s = record[i];
        if(s[0]=='E'){
            int space1 = s.find(" ");
            int space2 = s.find(" ", space1+1);
            string id = s.substr(space1+1, space2-space1-1);
            string name = s.substr(space2+1);
            data.push_back(make_pair('E', id));
            bool add=true;
            for(int j=0; j<info.size(); ++j){
               if(info[j].first==id){
                    info[j].second = name;
                    add = false;
                    break;
                }
            }
            if(add) info.push_back(make_pair(id, name));
        }
        else if(s[0]=='C'){
            int space1 = s.find(" ");
            int space2 = s.find(" ", space1+1);
            string id = s.substr(space1+1, space2-space1-1);
            string name = s.substr(space2+1);\
            for(int j=0; j<info.size(); ++j){
                if(info[j].first==id){
                    info[j].second = name;
                    break;
                }
            }
        }
        else{
            int space1 = s.find(" ");
            string id = s.substr(space1+1);
            data.push_back(make_pair('L', id));
        }
    }
    for(int i=0; i<data.size(); ++i){
        string ans;
        if(data[i].first=='E'){
            for(int j=0; j<info.size(); ++j){
                ans = info[j].second;
                if(data[i].second == info[j].first){
                    ans += "´ÔÀÌ µé¾î¿Ô½À´Ï´Ù.";
                    answer.push_back(ans);
                    break;
                }
            }
        }
        else{
            for(int j=0; j<info.size(); ++j){
                ans = info[j].second;
                if(data[i].second == info[j].first){
                    ans += "´ÔÀÌ ³ª°¬½À´Ï´Ù.";
                    answer.push_back(ans);
                    break;
                }
            }
        }
    }
    // for(int i=0; i<answer.size(); ++i)
    //     cout<<answer[i]<<'\n';
    return answer;
}
