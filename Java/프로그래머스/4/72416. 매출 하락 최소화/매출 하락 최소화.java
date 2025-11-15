import java.util.*;

class Solution {
    static List<Integer>[] tree;
    static int[][] dp;  // dp[i][0] = i 불참, dp[i][1] = i 참석
    static int[] sales;

    public int solution(int[] sales, int[][] links) {
        int n = sales.length;
        this.sales = sales;

        tree = new ArrayList[n + 1];
        dp = new int[n + 1][2];
        for (int i = 1; i <= n; i++) {
            tree[i] = new ArrayList<>();
        }

        for (int[] link : links) {
            int a = link[0];
            int b = link[1];
            tree[a].add(b);
        }

        dfs(1);
        return Math.min(dp[1][0], dp[1][1]);
    }

    private void dfs(int node) {
        dp[node][1] = sales[node - 1]; // 참석
        dp[node][0] = 0;               // 불참

        if (tree[node].isEmpty()) return;

        int sum = 0;
        int extra = Integer.MAX_VALUE;
        boolean hasAttendee = false;

        for (int child : tree[node]) {
            dfs(child);

            if (dp[child][0] < dp[child][1]) {
                sum += dp[child][0];
                extra = Math.min(extra, dp[child][1] - dp[child][0]);
            } else {
                sum += dp[child][1];
                hasAttendee = true;
            }
        }

        dp[node][1] += sum;                 // 자신 참석
        dp[node][0] = sum + (hasAttendee ? 0 : extra); // 불참 시 자식 중 한 명 참석 보장
    }
}