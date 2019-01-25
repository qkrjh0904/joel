#include<iostream>
using namespace std;
struct vector{
	double x,y;
	void add(const vector& vc){
		x += vc.sum();
		y += vc.sum();	
	}
	double sum(void) const{
		return x+y;
	}
	void print(void) const;
};
void vector::print(void) const
{
	cout << x << ' ' << y << endl;
}
int main(void)
{
	const vector v1 = {1.1, 2.2};
	vector v2 = {3.3, 5.5};
	
	v1.print();
	v2.print();
	v2.add(v1);
	v2.print();
		
	return 0;
}
