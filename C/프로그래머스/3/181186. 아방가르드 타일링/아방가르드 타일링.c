#include <stdio.h>
#define MOD 1000000007

int solution(int n) {
    if (n == 0) return 1;
    if (n == 1) return 1;
    if (n == 2) return 3;
    if (n == 3) return 10;

    long long dp[n+1];
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 3;
    dp[3] = 10;
    dp[4] = 23;
    dp[5] = 62;
    dp[6] = 170;

    for (int i = 7; i <= n; i++) {
        dp[i] = (dp[i-1] 
                + 2 * dp[i-2] % MOD 
                + 6 * dp[i-3] % MOD 
                + dp[i-4] 
                - dp[i-6] 
                + MOD) % MOD;
    }

    return (int)dp[n];
}