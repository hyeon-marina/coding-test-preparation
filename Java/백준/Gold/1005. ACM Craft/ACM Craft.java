import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        while (T-- > 0) {
            int N = sc.nextInt();
            int K = sc.nextInt();
            int[] time = new int[N+1];
            int[] dp = new int[N+1];
            ArrayList<Integer>[] adj = new ArrayList[N+1];
            int[] indegree = new int[N+1];
            for (int i=1; i<=N; i++) {
                time[i] = sc.nextInt();
                dp[i] = time[i];
                adj[i] = new ArrayList<>();
            }
            for (int i=0; i<K; i++) {
                int X = sc.nextInt();
                int Y = sc.nextInt();
                adj[X].add(Y);
                indegree[Y]++;
            }
            int W = sc.nextInt();
            Queue<Integer> q = new LinkedList<>();
            for (int i=1; i<=N; i++) if (indegree[i]==0) q.add(i);
            while (!q.isEmpty()) {
                int now = q.poll();
                for (int nxt : adj[now]) {
                    dp[nxt] = Math.max(dp[nxt], dp[now]+time[nxt]);
                    indegree[nxt]--;
                    if (indegree[nxt]==0) q.add(nxt);
                }
            }
            System.out.println(dp[W]);
        }
    }
}
