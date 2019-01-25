#include<iostream>
using namespace std;
typedef int (* PFL[5])(int);
void line(PFL pfl, int n)
{
	int i,j,k;
	for(j=0; j<n; j=j+1){
		for(k=0; k<5; ++k)
			for(i=0; i<pfl[k](j); ++i)
				if(k%2==0) cout << "* ";
				else cout << ". ";
			cout << endl;
	}
}
int f0(int i) { return 0; }
int f1(int i) { return 9-(i+1)/2; }
int f2(int i) { return 1+(i+1)/2*2; }
int f3(int i) { return 4-(i+1)/2; }
int f4(int i) { return 9-(i+1)/2*2; }

int main(void)
{
	PFL pf_list0 = {f0, f1, f2, f1, f0};
	PFL pf_list1 = {f3, f2, f4, f2, f3};
	
	line(pf_list0, 10);
	line(pf_list1, 9);
	
	
		
	return 0;
}
