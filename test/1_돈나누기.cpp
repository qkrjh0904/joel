#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int money) {
    vector<int> w(9);
    while(money>0){
        if(money>=50000){//5만
            w[0]++;
            money -= 50000;
        }
        else if(money>=10000){//1만
            w[1]++;
            money -= 10000;
        }
        else if(money>=5000){//5천
            w[2]++;
            money -= 5000;
        }
        else if(money>=1000){//1천
            w[3]++;
            money -= 1000;
        }
        else if(money>=500){//500
            w[4]++;
            money -= 500;
        }
        else if(money>=100){//100
            w[5]++;
            money -= 100;
        }
        else if(money>=50){//50
            w[6]++;
            money -= 50;
        }
        else if(money>=10){//10
            w[7]++;
            money -= 10;
        }
        else if(money>=1){//1
            w[8]++;
            money -= 1;
        }        
    }

    return w;
}
int main(){
	int money = 66666;
	vector<int> ans = solution(money);
	for(int i=0; i<ans.size(); ++i)
		cout<<ans[i]<<' ';
	cout<<endl;
	return 0;
}
