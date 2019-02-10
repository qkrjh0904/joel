#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Person{
	string name;
	int kor;
	int eng;
	int math;
};

bool cmp(const Person &u, const Person &v){
//	if(u.kor>v.kor){
//		return true;
//	}
//	else if(u.kor==v.kor){
//		if(u.eng<v.eng)
//			reutnr true;
//		else if(u.eng==v.eng){
//			if(u.math>v.math){
//				return true;
//			}
//			else if(u.math==v.math){
//				return u.name<v.name;
//			}
//		}
//	}
//	return false;
	
	return u.kor>v.kor || u.kor==v.kor&&u.eng<v.eng || u.kor==v.kor&&u.eng==v.eng&&u.math>v.math || u.kor==v.kor&&u.eng==v.eng&&u.math==v.math&&u.name<v.name;
}

void answer(){
	int n;
	cin>> n;
	
	vector< Person > v(n);
	for(int i=0; i<n; ++i){
		cin>> v[i].name >> v[i].kor >> v[i].eng >> v[i].math ;
	}
	
	sort(v.begin(), v.end(), cmp);
	for(int i=0; i<n; ++i)
		cout<<v[i].name<<'\n';
} 

int main(){
	answer();
	return 0;
}
