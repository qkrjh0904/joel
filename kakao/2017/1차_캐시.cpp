#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    //캐시 사이즈가 0인경우 예외처리로 바로 계산
    if(cacheSize==0){
        return cities.size()*5;
    }
    //대소문자 구분이 없으므로 먼저 소문자로 통일시켜줌
    for(int i=0; i<cities.size(); ++i){
        for(int j=0; j<cities[i].length(); ++j){
            if(cities[i][j]<97)
                cities[i][j] += 32;
        }   
    }
    //소문자로 잘 변경 되었는지 출력
    // for(int i=0; i<cities.size(); ++i){
    //     cout<<cities[i]<<' ';
    // }cout<<endl;
    
    //캐시 생성
    vector<pair<string, int> > cache;
    int cnt=0;
    for(int i=0; i<cities.size(); ++i){
        string city = cities[i];
        bool hit = false;
        for(int j=0; j<cache.size(); ++j){
            if(city==cache[j].first){
                hit = true;
                cache[j].second = cnt++;    //hit 하였으면 최근에 사용되었기때문에 cnt만 최신화시켜줌
                break;
            }
        }
        //hit이라면 answer 1추가, miss라면 answer 5추가 후 가장 오래된것 제거후 넣기
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
                // cout<<"현재 도시: "<<city<<" 현재 min : "<<min<<endl;
                for(int k=0; k<cache.size(); ++k){
                    if(min==cache[k].second){
                        cache[k].first = city;
                        cache[k].second = cnt;
                    }
                }
                
            }
            cnt++;
        }
        //현재 캐시 상태 출력
        // for(int k=0; k<cache.size(); ++k){
        //     cout<<cache[k].first<<' '<<cache[k].second<<endl;
        // }cout<<"answer : "<<answer<<endl<<endl;
        
    }
    
    
    return answer;
}
