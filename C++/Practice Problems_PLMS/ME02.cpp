#include<iostream>
using namespace std;
int* copy(const int src[], int len)
{
	int* dst = new int[len];
	for(int i=0; i<len; ++i)
		dst[i] = src[i];
	return dst;
}
int main(void)
{
	int* p;
	int a[] = {55, 22, 33, 11, 55};
	const int len_a = sizeof(a)/sizeof(a[0]);
	
	p = copy(a, len_a);
	for(int i=0; i<len_a; ++i)
		cout << p[i] << ' ';
	cout << endl;
	delete p;
	
	int b[] = {99, 77, 88};
	const int len_b = sizeof(b)/sizeof(b[0]);
	
	p = copy(b, len_b);
	for(int i=0; i<len_b; ++i)
		cout << p[i] << ' ';
	cout << endl;
	delete p;
	
	return 0;
}
