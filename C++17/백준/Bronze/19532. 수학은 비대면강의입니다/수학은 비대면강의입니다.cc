#include <iostream>
using namespace std;

int main() {
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;

    int det = a * e - b * d;              // 행렬식
    int x = (c * e - b * f) / det;
    int y = (a * f - c * d) / det;

    cout << x << " " << y;
    return 0;
}