#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int nums[5];
    int sum = 0;
    for(int i = 0; i < 5; i++){
        cin >> nums[i];
        sum += nums[i];
    }
    sort(nums, nums + 5);
    int avg = sum / 5;
    int mid = nums[2];
    cout << avg << "\n" << mid << "\n";
    return 0;
}