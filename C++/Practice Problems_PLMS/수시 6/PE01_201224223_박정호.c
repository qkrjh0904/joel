#include<stdio.h>

int main(){
	
	int a, r, ai, s;
	int n, i;
	
	scanf("%d%d%d",&a, &r, &n);
	
	ai = a;
	s = 0;
	for(i=0; i<n; i=i+1){
		if(i==n-1) 
			printf("+ ");
		else 
			printf("  ");
		printf("%d\n", ai);
		s += ai;
		ai *= r;
	}
	printf("============\n  %d\n", s);
	return 0;
}
