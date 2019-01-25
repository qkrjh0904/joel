#include<stdio.h>

void line(int* a, int* d, int j)
{
	int i, k;
	
	for(k=0; k<4; ++k)
		for(i=0; i<a[k]+d[k]*j; ++i)
			if(k%2 == 0)
				printf(". ");
			else
				printf("* ");
}

void section(int* a, int *d, int n)
{
	int j;
	
	for(j=0; j<n; ++j){
		line(a, d, j);
		printf("\n");
	}
}

int main(void)
{
	int a0[4] = {9, 1, 9, 0};
	int d0[4] = {-1, 2, -1, 0};
	int a1[4] = {0, 1, 17, 1};
	int d1[4] = {0, 1, -2, 1};
	
	section(a0, d0, 10);
	section(a1, d1, 9);
	return 0;
}
