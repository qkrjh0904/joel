#include <stdio.h>

struct vec2{
	int x,y;
};

struct vec2* vec2_vec2(struct vec2* this, int _x, int _y){
	this->x = _x;
	this->y = _y;
	return this;
}

int vec2_sum(const struct vec2* this){
	return this->x + this->y;
}

struct vec3{
	int x,y;
	int z;
};

struct vec3* vec3_vec3(struct vec3* this, int _x, int _y, int _z){
	vec2_vec2((struct vec2*) this, _x, _y);
	this->z = _z;
	return this;
}

int vec3_sum(const struct vec3* this){
	return vec2_sum((const struct vec2*)this) + this->z;
}

int main(void)
{
   struct vec2 v2;
   struct vec3 v3;
   struct vec2* p1=&v2;
   struct vec2* p2=(struct vec2*)&v3;
   struct vec3* p3=&v3;
   
   vec2_vec2(&v2, 11, 22);
   vec3_vec3(&v3, 111, 222, 333);
   printf("%d\n", vec2_sum(p1));
   printf("%d\n", vec2_sum(p2));
   printf("%d\n", vec3_sum(p3));
   
   
   return 0;
}
