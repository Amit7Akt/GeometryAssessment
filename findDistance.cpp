#include<iostream>

struct point {
	float a;
	float b;
	float c;
};
float findDistance(point p1, point p2) {
	float x = p1.a - p2.a;
	float y = p1.b - p2.b;
	float z = p1.c - p2.c;
	
	float distance = sqrtf((x * x) + (y * y) + (z * z));
	return distance;


}
int main() {
	point p1 = { 1,2,4 };
	point p2 = { 3,4,5 };
	std::cout << "The distance between these points  is: " << findDistance(p1, p2);
	return 0;
}