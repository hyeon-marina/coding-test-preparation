#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

struct Member {
    int age;
    string name;
    int order;
};

bool cmp(const Member &a, const Member &b) {
    if (a.age != b.age) {
        return a.age < b.age;
    } else {
        return a.order < b.order;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    vector<Member> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i].age >> arr[i].name;
        arr[i].order = i;
    }
    sort(arr.begin(), arr.end(), cmp);
    for (const auto &m : arr) {
        cout << m.age << " " << m.name << "\n";
    }
    return 0;
}