import java.util.*;

class Solution {
    public int[] solution(int n, int[][] roads, int[] sources, int destination) {
        List<Integer>[] adj = new ArrayList[n + 1];
        for (int i = 1; i <= n; i++) adj[i] = new ArrayList<>();

        for (int[] e : roads) {
            int a = e[0], b = e[1];
            adj[a].add(b);
            adj[b].add(a);
        }

        int[] dist = new int[n + 1];
        Arrays.fill(dist, -1);

        ArrayDeque<Integer> q = new ArrayDeque<>();
        q.add(destination);
        dist[destination] = 0;

        while (!q.isEmpty()) {
            int cur = q.poll();
            for (int nxt : adj[cur]) {
                if (dist[nxt] == -1) {
                    dist[nxt] = dist[cur] + 1;
                    q.add(nxt);
                }
            }
        }

        int[] ans = new int[sources.length];
        for (int i = 0; i < sources.length; i++) {
            ans[i] = dist[sources[i]];
        }
        return ans;
    }
}
