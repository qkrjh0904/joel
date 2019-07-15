#include <iostream>

using namespace std;

int main(){
    int num;
    cin>>num;

    int answer=0;
    int quotient = num/5;        //¸ò
    for(int i=quotient; i>=0; i--){
        int temp = num - 5*i;
        if(temp%3==0){
            answer = i+temp/3;
            cout<<answer<<'\n';
            return 0;
        }
    }
    cout<<-1<<'\n';
    return 0;

}
