#include <iostream>

using namespace std;

struct Vector {
    double x, y;
};
  
struct Line {
    double slope, y_intercept;
};

Line get_line_from_vector(Vector v) {
    double slope = v.y / v.x;
    double y_intercept = 0;
    if (v.x != 0) {
        y_intercept = -v.y / v.x * v.x + v.y;
    }
    return { slope, y_intercept };
}

Vector calculate_intersection_point(Line l1, Line l2) {
    double x = (l2.y_intercept - l1.y_intercept) / (l1.slope - l2.slope);
    double y = l1.slope * x + l1.y_intercept;
    return { x, y };
}

int main() {
    Vector v1 = { 2, 2 };
    Vector v2 = { 1, -1 };
    Line l1 = get_line_from_vector(v1);
    Line l2 = get_line_from_vector(v2);
    Vector intersection_point = calculate_intersection_point(l1, l2);
    cout << "Intersection Point: (" << intersection_point.x << ", " << intersection_point.y << ")" << endl;
    return 0;
}
