#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    vector<int> arr(N);
    for(int i=0;i<N;i++){
        cin >> arr[i];
    }

    vector<int> sorted = arr;
    sort(sorted.begin(), sorted.end());
    sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());

    for(int i=0;i<N;i++){
        int v = arr[i];
        int idx = lower_bound(sorted.begin(), sorted.end(), v) - sorted.begin();
        cout << idx << ' ';
    }
    cout << '\n';

    return 0;
}