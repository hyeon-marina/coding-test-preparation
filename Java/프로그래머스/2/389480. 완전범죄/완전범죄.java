class Solution {
    public int solution(int[][] info, int n, int m) {
        final int INF = Integer.MAX_VALUE / 2;
        int[] dp = new int[m];
        int[] ndp = new int[m];
        for (int i = 0; i < m; i++) dp[i] = INF;
        dp[0] = 0;

        for (int i = 0; i < info.length; i++) {
            for (int j = 0; j < m; j++) ndp[j] = INF;
            int a_tr = info[i][0];
            int b_tr = info[i][1];
            for (int b_sum = 0; b_sum < m; b_sum++) {
                if (dp[b_sum] == INF) continue;
                // 1. A도둑이 담당
                int a_sum = dp[b_sum] + a_tr;
                if (a_sum < n) {
                    ndp[b_sum] = Math.min(ndp[b_sum], a_sum);
                }
                // 2. B도둑이 담당
                int nb_sum = b_sum + b_tr;
                if (nb_sum < m) {
                    ndp[nb_sum] = Math.min(ndp[nb_sum], dp[b_sum]);
                }
            }
            // swap dp, ndp
            int[] tmp = dp;
            dp = ndp;
            ndp = tmp;
        }

        int answer = INF;
        for (int i = 0; i < m; i++) {
            answer = Math.min(answer, dp[i]);
        }
        if (answer == INF) return -1;
        return answer;
    }
}
