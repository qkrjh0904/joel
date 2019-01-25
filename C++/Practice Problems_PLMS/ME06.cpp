#include<iostream>
using namespace std;
class sequence{
	int* a;
	int sz, k;
	void set(int v){
		for(int i=0; i<sz; ++i)
			a[i]=v;	
	}
public:
	sequence(int _sz, int _k):a(new int[_sz]), sz(_sz), k(_k){
		set(k-1);
	}
	~sequence(void){
		delete a;
	}
	int number(void) const{
		int m=1, i;
		for(i=0; i<sz; ++i)
			m*=k;
		return m;
	}
	void next(void){
		int i;
		for(i=sz-1; i>=0 && !(a[i]!=0); --i)
			a[i]=k-1;
		if(i>=0)
			--a[i];
		
	}
	void print(void) const{
		for(int i=0; i<sz; ++i)
			cout << a[i] << ' ';
		cout << endl;
	}
		
};
int main(void)
{
	int sz, k;
	cin >> sz >> k;
	
	sequence sq(sz, k);
	int n = sq.number();
	for(int i=0; i<n; ++i){
		sq.print();
		sq.next();	
	}
	return 0;

}
