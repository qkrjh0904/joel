#include <iostream>

#define NAME_SIZE 50

using namespace std;

class Person{
	int id;
	char name[NAME_SIZE];
	
public:
	virtual void aboutMe(){
		cout<<"I am a person."<<'\n';
	}		
	virtual bool addCourse(string s) = 0;
};

class Student : public Person{
public:
	void aboutMe(){
		cout<<"I am a student."<<'\n';
	}
	
	bool addCourse(string s){
		cout<<"Added course "<< s <<" to student." <<'\n';
		return true;
	}
};

int main(void){
	Person *p = new Student();
	p->aboutMe();	//"I am a student." 출력 
	p->addCourse("C++ programming");
	delete p;	//할당 받은 메모리를 반환하는것이 중요! 
	return 0;	
}
