#include<iostream>

using namespace std;

class vec2{
	int x,y;
public:
	vec2(int _x, int _y)
		: x(_x), y(_y){}
	operator int(void) const{
		return x+y;
	}
};

class vec3{
	vec2 vc2;
	int z;
public:
	vec3(int _x, int _y, int _z)
		: vc2(_x, _y), z(_z){}
	operator vec2(void) const {
		return vc2;
	}
};

int main(void)
{
	vec2 v2(11, 22);
	vec3 v3(111, 222, 333);
	cout << int(v2) << ' ';
	cout << vec2(v3) <<endl;
	
	return 0;

}
