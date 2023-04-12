#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double x, y, r, distance;

    cout << "Enter the X co-ordinate: ";
    cin >> x;

    cout << "Enter the Y co-ordinate: ";
    cin >> y;

    cout << "Enter the radius of Circle: ";
    cin >> r;

    distance = sqrt(pow(x, 2) + pow(y, 2));

    if (distance < r) {
        cout << "Result: Point lies inside the circle" << endl;
    }
    else if (distance == r) {
        cout << "Result: Point lies on the circle" << endl;
    }
    else {
        cout << "Result: Point lies outside the circle" << endl;
    }

    return 0;
}
