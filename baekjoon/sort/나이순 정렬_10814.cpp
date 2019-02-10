#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Person{
	int age;
	string name;
};

bool cmp(const Person &u, const Person &v){
	return u.age<v.age;
}

void answer(){
	int n;
	cin>> n;
	
	vector< Person > v(n);
	for(int i=0; i<n; ++i){
		cin>> v[i].age >> v[i].name ;
	}
	
	stable_sort(v.begin(), v.end(), cmp);
	for(int i=0; i<n; ++i)
		cout<<v[i].age<<' '<<v[i].name<<'\n';
} 

int main(){
	answer();
	return 0;
}
