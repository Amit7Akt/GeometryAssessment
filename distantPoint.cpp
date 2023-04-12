#include<iostream>
using namespace std;

struct point {
	float x;
	float y;
	float z;

	friend ostream& operator<<(std::ostream& os, const point& point) {
		os << "(" << point.x << ", " << point.y << ", " << point.z << ")";
		return os;
	}
};

point distantPoint(point p1, point p2, float distance) {
	//find the x,y,z of the distance vector
	float x1 = p2.x - p1.x;
	float y1 = p2.y - p1.y;
	float z1 = p2.z - p1.z;

	//find the unit vector and multiply by 2 to find the tip of hte vector

	float magn = sqrtf((x1 * x1) + (y1 * y1) + (z1 * z1));

	float ux1 = (x1 / magn)*distance;
	float uy1 = (y1 / magn)*distance;
	float uz1 = (z1 / magn)*distance;

	//the cordinates of the point are 
	float x2 = ux1 + p1.x;
	float y2 = uy1 + p1.y;
	float z2 = uz1 + p1.y;

	point pS = { x2,y2,z2 };
	return pS;
}

int main() {
	point p1 = { 1,2,3 };
	point p2 = { 4,5,6 };
	float distance = 2;
	cout << distantPoint(p1, p2, distance);
}
