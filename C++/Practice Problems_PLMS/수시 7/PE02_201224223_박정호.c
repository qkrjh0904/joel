#include<stdio.h>

int multi(int k, int sz)
{
	int i, m=1;
	
	for(i=0; i<sz; ++i)
		m *= k;
	return m;
}
void print(int* a, int sz)
{
	int i;
	
	for(i=0; i<sz; ++i)
		printf("%d ", a[i]);
	printf("\n");
}
void prev(int* a, int sz, int k)
{
	int i;
	
	for(i=sz-1; i>=0 && !(a[i]!=0); --i)
		a[i]=k-1;
	if(i>=0)
		--a[i];
}
int main(void)
{
	int a[100] = {0, };
	int sz, k, n;
	int j;
	 
	scanf("%d%d", &sz, &k);
	n = multi(k, sz);
	for(j=0; j<=n; ++j){
		prev(a, sz, k);
		print(a, sz);
	}
	return 0;
}
