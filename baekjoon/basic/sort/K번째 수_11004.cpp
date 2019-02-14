#include <iostream>
#include <algorithm>

using namespace std;

int a[5000000];
void answer(){
	int n, k;
	scanf("%d%d",&n, &k);
	k -= 1;
	
	for(int i=0; i<n; ++i){
		scanf("%d", &a[i]);
	}
	nth_element(a, a+k, a+n);
	printf("%d\n", a[k]);
} 

int main(){
	answer();
	return 0;
}
