#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    //ĳ�� ����� 0�ΰ�� ����ó���� �ٷ� ���
    if(cacheSize==0){
        return cities.size()*5;
    }
    //��ҹ��� ������ �����Ƿ� ���� �ҹ��ڷ� ���Ͻ�����
    for(int i=0; i<cities.size(); ++i){
        for(int j=0; j<cities[i].length(); ++j){
            if(cities[i][j]<97)
                cities[i][j] += 32;
        }   
    }
    //�ҹ��ڷ� �� ���� �Ǿ����� ���
    // for(int i=0; i<cities.size(); ++i){
    //     cout<<cities[i]<<' ';
    // }cout<<endl;
    
    //ĳ�� ����
    vector<pair<string, int> > cache;
    int cnt=0;
    for(int i=0; i<cities.size(); ++i){
        string city = cities[i];
        bool hit = false;
        for(int j=0; j<cache.size(); ++j){
            if(city==cache[j].first){
                hit = true;
                cache[j].second = cnt++;    //hit �Ͽ����� �ֱٿ� ���Ǿ��⶧���� cnt�� �ֽ�ȭ������
                break;
            }
        }
        //hit�̶�� answer 1�߰�, miss��� answer 5�߰� �� ���� �����Ȱ� ������ �ֱ�
        if(hit){
            answer += 1;    
        }
        else{
            answer += 5;
            if(cache.size()<cacheSize)
                cache.push_back(make_pair(city, cnt));
            else{
                int min = cache[0].second;
                for(int k=1; k<cache.size(); ++k){
                    if(min>cache[k].second)
                        min = cache[k].second;
                }
                // cout<<"���� ����: "<<city<<" ���� min : "<<min<<endl;
                for(int k=0; k<cache.size(); ++k){
                    if(min==cache[k].second){
                        cache[k].first = city;
                        cache[k].second = cnt;
                    }
                }
                
            }
            cnt++;
        }
        //���� ĳ�� ���� ���
        // for(int k=0; k<cache.size(); ++k){
        //     cout<<cache[k].first<<' '<<cache[k].second<<endl;
        // }cout<<"answer : "<<answer<<endl<<endl;
        
    }
    
    
    return answer;
}
