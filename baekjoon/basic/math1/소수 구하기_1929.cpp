#include <iostream>

using namespace std;

bool isPrime(int n){
	if( n<2 )
		return false;
	else{
		for(int i=2; i*i<=n; ++i){
			if( n%i==0 )
				return false;
		}
	}
	return true;
}

void answer(){
	int n1, n2;
	cin>>n1>>n2;
	int answer=0;
	
	for(int i=n1; i<=n2; ++i){
		if( isPrime(i) ){
			cout<<i<<'\n';
		}		
	}
}

int main(void){
	answer();
	
	return 0;
}

/*
�����佺�׳׽��� ü ��� ���

#include <iostream>
using namespace std;
const int MAX = 1000000;
bool check[MAX+1]; // true: ������, false: �������� ����
int main() {
    check[0] = check[1] = true;
    for (int i=2; i*i<=MAX; i++) {
        if (check[i] == false) {
            for (int j=i+i; j<=MAX; j+=i) {
                check[j] = true;
            }
        }
    }
    
    int m, n;
    cin >> m >> n;
    for (int i=m; i<=n; i++) {
        if (check[i] == false) {
            cout << i << '\n';
        }
    }

    return 0;
} 
*/
