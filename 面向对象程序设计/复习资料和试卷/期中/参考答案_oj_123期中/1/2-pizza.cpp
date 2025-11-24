
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

const double PI = 3.14159265358979323846;

double pizza_area(double r, double a) {
    return (PI * r * r * a) / 360.0;
}

int main() {
    int n;
    cin >> n;

    double total_area = 0.0;

    for (int i = 0; i < n; ++i) {
        double r, a;
        cin >> r >> a;
        total_area += pizza_area(r, a);
    }

    cout << fixed << setprecision(3) << total_area << endl;

    return 0;
}