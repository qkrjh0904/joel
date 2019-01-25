#include<stdio.h>

int main(){
	
	int beg, end, i;
	int sum;
	
	scanf("%d%d", &beg, &end);
	
	sum = 0;
	for(i=beg; i<=end; i=i+1)
		if(i!=0 && (588%i==0 || 945%i==0)){
			printf("%d ",i);
			sum += i;
		}
	printf("\nsum = %d\n",sum);
	
	return 0;
}
