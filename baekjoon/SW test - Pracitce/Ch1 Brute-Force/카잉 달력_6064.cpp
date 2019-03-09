#include <iostream>

using namespace std;

void answer(){
	int m, n, x, y;
	scanf("%d %d %d %d", &m, &n, &x, &y);
	if(m<n){
		int temp = m;
		m = n;
		n = temp;
		
		temp = x;
		x = y;
		y = temp;
	}
	
	int cnt=0;
	int answer = x;
	int now_y = x;
	while(true){
		while(now_y>n)
			now_y -= n;
		if(now_y==y){
			cout<<answer<<'\n';
			break;
		}
		now_y += m;
		answer += m;
		cnt++;
		if(cnt>40000){
			cout<<-1<<'\n';
			break;
		}
	}
	
//	int max = m*n;
//	int answer=1;
//	int now_x=1, now_y=1;
//	while(true){
//		if(now_x>m)
//			now_x -= m;
//		if(now_y>n)
//			now_y -= n;
//		if(now_x==x && now_y==y){
//			printf("%d\n", answer);
//			break;
//		}
//		now_x++;
//		now_y++;
//		answer++;
//		if(answer>max){
//			printf("%d\n", -1);
//			break;
//		}
//	}
}

int main(){
	int tc;
	scanf("%d", &tc);
	while( tc!=0 ){
		tc--;
		answer();
	}
}
