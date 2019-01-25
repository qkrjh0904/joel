#include<stdio.h>

int main(){
	
	double a[100] = {1.1, 2.2, 3.3, 4.4};
	int len = 4, i, j;
	int remove_index;
	double new_value;
	
	scanf("%d", &remove_index);
	scanf("%lf", &new_value);
	
	
	j = remove_index;
	for(i=j+1; i<len; i=i+1){
		a[j++] = a[i];
	}
	len = j;
	
	a[len++] = new_value;
	
	for(i=0; i<len; i=i+1)
		printf("%f ",a[i]);
	printf("\n");
	return 0;
}
