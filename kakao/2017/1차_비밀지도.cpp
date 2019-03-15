#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer(n);
    //지도 크기만큼 벽 생성
    string s;
    for(int i=0; i<n; ++i){
        s += '#';
    }
    //일단 정답을 모두 벽으로 초기화
    for(int i=0; i<n; ++i){
        answer[i] = s;
    }

    vector<int> map(arr1.size());
    //두 지도의 or연산을 map 벡터에 정수형으로 저장
    for(int i=0; i<map.size(); ++i){
        int x = arr1[i];
        int y = arr2[i];
        int z = x|y;
        map[i] = z;
        //z출력
        // cout<<z<<' ';
    }
    // cout<<'\n';
    for(int i=0; i<map.size(); ++i){
        //끝자리부터 만약 0이라면 공백부분으로 변경시켜줌.
        int x = map[i];
        int change = n-1;
        while(true){
            if(x%2==0)
                answer[i][change] = ' ';
            x/=2;
            if(change==0)
                break;
            change--;
        }
    }
    //정답 출력
    // for(int i=0; i<n; ++i)
    //     cout<<answer[i]<<' ';
    // cout<<endl;



    return answer;
}
