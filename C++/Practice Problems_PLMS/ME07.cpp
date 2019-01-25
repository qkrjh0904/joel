#include<iostream>
using namespace std;
class array{
	int* pa;
	int sz;
public:
	array(void): pa(NULL), sz(0){}
	array(int _sz){
		pa = new int[_sz];
		sz = _sz;
	}
	array(const array& mc){
		pa = new int[mc.sz];
		sz = mc.sz;
		for(int i=0; i<mc.sz; ++i)
			pa[i] = mc.pa[i];
	}
	~array(void){
		if(pa!=NULL)
			delete pa;	
	}
	int size(void) const{
		return sz;
	}
	int* ptr(void){
		return pa;
	}
};
int main(void)
{
	array a, b(3), c(2);
	
	b.ptr()[0] = 11;
	b.ptr()[1] = 22;
	b.ptr()[2] = 33;
	
	c.ptr()[0] = 44;
	c.ptr()[1] = 55;
	
	array d(c);
	
	for(int i=0; i<b.size(); ++i)
		cout << b.ptr()[i] << ' ';
	cout << endl;
	
	for(int i=0; i<c.size(); ++i)
		cout << c.ptr()[i] << ' ';
	cout << endl;
	
	for(int i=0; i<d.size(); ++i)
		cout << d.ptr()[i] << ' ';
	cout << endl;
	
	return 0;

}
