#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string dartResult) {
    vector<string> n(3);  //각 다트에서 나온 점수
    vector<char> b(3);  //각 다트의 보너스
    vector<char> o(3);  //각 다트의 옵션
    int cnt=0;      //dartResult의 문자 위치
    int index=0;    //각 다트의 index
    while(true){
        //index가 3이 넘거나, cnt가 dartResult크기보타 크면 break
        if(cnt==dartResult.size() || index==3)
            break;
        //dartResult의 문자가 숫자면 n[index]에 입력
        if(dartResult[cnt]>='0' && dartResult[cnt]<='9'){
            n[index] += dartResult[cnt];
            cnt++;
            continue;   //10의 경우는 문자가 두개이므로 다시 되돌아가서 1다음 0이 나오는지 또 확인해야함
        }
        if(dartResult[cnt]=='S' || dartResult[cnt]=='D' || dartResult[cnt]=='T'){
            b[index] += dartResult[cnt];
            cnt++;
        }
        if(dartResult[cnt]=='*' || dartResult[cnt]=='#'){
            o[index] += dartResult[cnt];
            cnt++;
        }
        index++;
    }
    //숫자, 보너스, 옵션이 모두 잘 출력되었는지 확인 출력
    for(int i=0; i<3; ++i){
        cout<<n[i]<<' '<<b[i]<<' '<<o[i]<<'\n';
    }
    
    //기본점수+보너스 계산인 basic과 옵션 점수 계산인 mul 벡터 생성
    vector<int> basic(3);
    vector<int> mul(3);
    //기본+보너스 점수 계산
    for(int i=0; i<3; ++i){
        int input=stoi(n[i]);
        if(b[i]=='D')   //D면 제곱
            input = input*input;
        else if(b[i]=='T')  //T면 세제곱
            input = input*input*input;
        basic[i] = input;
    }
    //옵션점수 계산
    for(int i=0; i<3; ++i){
        int input=1;
        if(o[i]=='*'){  
            input *= 2;
            if(i>0)
                mul[i-1] *= 2;  //index가 1이상인경우 이전의 점수도 2배
        }
        else if(o[i]=='#')
            input *= -1;    //#이면 현재점수 -1
        mul[i] = input;
    }
    //basic과 mul이 잘 계산되었는지 출력
    for(int i=0; i<3; ++i)
        cout<<basic[i]<<' ';
    cout<<endl;
    for(int i=0; i<3; ++i)\
        cout<<mul[i]<<' ';
    cout<<endl;
    
    int answer = 0;
    for(int i=0; i<3; ++i){
        answer += (basic[i]*mul[i]);    //basic과 mul의 곱의 합이 답이된다.
    }
    return answer;
}
