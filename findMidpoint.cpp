#include<iostream>

using namespace std;
struct point {
	float a; 
	float b;
	float c;

	friend std::ostream& operator<<(std::ostream& os, const point& point) {
		os << "(" << point.a<< ", " << point.b << ", " << point.c << ")";
		return os;
	}
};

point findMidpoint(point p1, point p2) {
	float x = ((p1.a) + (p2.a)) / 2;
	float y = (p1.b + p2.b) / 2;
	float z = (p1.c + p2.c) / 2;
	point p3 = { x,y,z };
	return p3;
}

int main() {
	point a = { 1,2,3 };
	point b = { 3,5,6 };
	cout << findMidpoint(a, b);
	return 0;
}