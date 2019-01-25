#include <iostream>
#include <queue>

using namespace std; 

int main(void){
	
	int N, M;
	cin>>N>>M;
	
	queue<int> q;
	for(int i=1; i<=N; ++i)
		q.push(i);
	
	int cnt=0;
	cout<<"<";
	while(!q.empty()){
		cnt++;
		if(cnt%M == 0){
			cout<<q.front();
			if(q.size() != 1)
				cout<<", ";
			q.pop();
		}
		else{
			q.push(q.front());
			q.pop();
		}
	}
	cout<<">"<<endl;

	
	return 0;
}
