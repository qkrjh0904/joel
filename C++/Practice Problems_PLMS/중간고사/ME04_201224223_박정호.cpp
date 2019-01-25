#include<iostream>
#include<fstream>

using namespace std;

const int MAX_LEN = 512;

class set{
	double a[MAX_LEN];
	int len;
	int contains(double v) const{
		for(int i=0; i<len; ++i)
			if(a[i]==v)
				return 1;
		return 0;
	}
	void remove_first(double v){
		int i;
		for(i=0; i<len && !(a[i]==v); ++i)
			;
		if(i<len)
			a[i] = a[--len];
	}
public:
	void clear(void){
		len = 0;	
	}
	int length(void) const{
		return len;
	}
	double at(int i) const{
		return a[i];
	}
	void append(double v){
		if(contains(v))
			return;
		if(len<MAX_LEN)
			a[len++] = v;
	}
	set operator+(const set& s){
		set t = *this;
		for(int i=0; i<s.length(); ++i)
			t.append(s.at(i));
		return t;
	}
	set operator-(const set& s){
		set t = *this;
		for(int i=0; i<s.length(); ++i)
			t.remove_first(s.at(i));
		return t;
	}
};
istream&
operator>>(istream& is, set& s)
{
	s.clear();
	double v;
	while(is >> v)
		s.append(v);
	return is;
}
ostream&
operator<<(ostream& os, set& s)
{
	os << "len == " << s.length() << ": ";
	for(int i=0; i<s.length(); ++i)
		os << s.at(i) << ' ';
	return os;
}

int main(int argc, char* argv[])
{
	set s1, s2, s3;
	
	s1.clear();
	s2.clear();
	s3.clear();
	
	
	if(argc!=3){
		cerr << "Invalid prog. args" <<endl;
		return -1;	
	}
	
	
	
	ifstream ifs1(argv[1]);
	if(!ifs1.is_open()){
		cerr << "Input file error." <<endl;
		return -1;
	}
	ifs1 >> s1;
	ifs1.close();
	
	ifstream ifs2(argv[2]);
	if(!ifs2.is_open()){
		cerr << "Input file error." <<endl;
		return -1;
	}
	ifs2 >> s2;
	ifs2.close();
	
	cout << s1 << endl;
	cout << s2 << endl;
	
	s3 = s1+s2;
	cout << s3 << endl;
	
	s3 = s1-s2;
	cout << s3 << endl;
	
	
		
	return 0;
}
