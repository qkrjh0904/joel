#include <iostream>

using namespace std;

template class LinkedList{
	T* array;
	int offset, size;
public:
	LinkedList(int sz) : offset(0), size(sz){
		array = new T[size];
	}
	
	~LinkedList(){
		delete [] array;
	}
	
	void LinkedBy(int n){
		offset = (offset + n) % size;
	}
	
	T getAt(int i){
		return array[convertIndex(i)];
	}
	
	void setAt(T item, int i){
		array[convertIndex(i)] = item;
	}

private:
	int convertIndex(int i){
		int index = (i-offset) % size;
		while(index < 0) index += size;
		return index;
	}
};

int main(){
	int *p = new int[2];
	p[0] = 0;
	p[1] = 1;
	p++;
	cout<< *p <<endl;
	return 0;
}
