#include<iostream>
using namespace std;

struct point {
	double x;
	double y;

	friend ostream& operator<<(ostream& os, const point& point)
	{
		os << "(" << point.x << ", " << point.y << ")";
		return os;

	}

};

 //CALCULATE THE VECTOR FORMED BY SG AND THEN FORM 
point findProjection(point g, point a, point s) {
	float dist = sqrt(a.x * a.x + a.y * a.y);
	//vector formed by SG
	 point sg{ g.x - s.x, g.y - s.y };

	float scaling_factor = (sg.x*a.x + sg.y* a.y) / (dist*dist);
	//now use this scaling factor to scale the vector on which the point is being 
	//projected 
	point ans{ 0,0 };
	ans.x = s.x + (scaling_factor * a.x );
	ans.y = s.y +(scaling_factor * a.y);
	return ans;
}
int main() {
	point s{ 1,2 };
	point e{ 3,4 };
	point g{ 2,8 };
	point a{ e.x - s.x, e.y - s.y };
	cout << findProjection(g, a, s);
}