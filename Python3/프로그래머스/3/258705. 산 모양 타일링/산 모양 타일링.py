def solution(n, tops):
    MOD = 10007
    if n == 1:
        return 3 if tops[0] == 1 else 2

    dp0 = 1
    dp1 = 3 if tops[0] == 1 else 2  # dp[1]

    # i = 2 .. 2n
    for i in range(2, 2 * n + 1):
        if (i & 1) == 1 and tops[i // 2] == 1:
            cur = (dp1 * 2 + dp0) % MOD
        else:
            cur = (dp1 + dp0) % MOD
        dp0, dp1 = dp1, cur

    return dp1
