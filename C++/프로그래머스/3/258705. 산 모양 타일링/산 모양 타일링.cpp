#include <vector>
using namespace std;

int solution(int n, vector<int> tops) {
    const int MOD = 10007;

    if (n == 1) return (tops[0] == 1) ? 3 : 2;

    int dp0 = 1;
    int dp1 = (tops[0] == 1) ? 3 : 2; // dp[1]

    for (int i = 2; i <= 2 * n; i++) {
        int cur;
        if ((i & 1) == 1 && tops[i / 2] == 1) {
            cur = (dp1 * 2 + dp0) % MOD;
        } else {
            cur = (dp1 + dp0) % MOD;
        }
        dp0 = dp1;
        dp1 = cur;
    }
    return dp1;
}
