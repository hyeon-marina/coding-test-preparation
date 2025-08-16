def solution(info, n, m):
    INF = float('inf')
    dp = [INF] * m  # dp[b]: B도둑의 누적 흔적이 b일 때 A도둑의 최소 흔적 합
    dp[0] = 0

    for a_tr, b_tr in info:
        ndp = [INF] * m
        for b_sum in range(m):
            if dp[b_sum] == INF:
                continue
            # 1. A도둑이 담당
            a_sum = dp[b_sum] + a_tr
            if a_sum < n:
                ndp[b_sum] = min(ndp[b_sum], a_sum)
            # 2. B도둑이 담당
            nb_sum = b_sum + b_tr
            if nb_sum < m:
                ndp[nb_sum] = min(ndp[nb_sum], dp[b_sum])
        dp = ndp

    answer = min(dp)
    return answer if answer != INF else -1
