#include<stdio.h>

int input(int* a, int max_n)
{
	int i, n;
	
	scanf("%d", &n);
	if(n>max_n)
		n=max_n;
	for(i=0; i<n; ++i)
		scanf("%d", &a[i]);
	return i;
}
void print(int* a, int n)
{
	int i;
	
	for(i=0; i<n; ++i)
		printf("%d ", a[i]);
	printf("\n");
}
int remove_dup(int a[], int n)
{
	int i, j, k;
	
	for(i=0, j=0; i<n; ++i){
		for(k=i+1; k<n && a[i]!=a[k]; ++k)
			;
		if(!(k<n))
			a[j++] = a[i];
	}
	return j;
}
int main(void)
{
	int a[100];
	int n, max_n=100;
	
	n = input(a, max_n);
	n = remove_dup(a, n);
	print(a, n);
	return 0;
}
