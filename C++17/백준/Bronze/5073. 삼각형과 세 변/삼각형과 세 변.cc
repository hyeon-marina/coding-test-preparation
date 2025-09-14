#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b, c;
    while (true) {
        cin >> a >> b >> c;
        if (a == 0 && b == 0 && c == 0) break;

        int sides[3] = {a, b, c};
        sort(sides, sides + 3);
        int x = sides[0], y = sides[1], z = sides[2];

        if (x + y <= z) {
            cout << "Invalid\n";
        } else {
            if (x == y && y == z) {
                cout << "Equilateral\n";
            } else if (x == y || y == z || x == z) {
                cout << "Isosceles\n";
            } else {
                cout << "Scalene\n";
            }
        }
    }
    return 0;
}