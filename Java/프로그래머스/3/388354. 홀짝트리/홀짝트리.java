import java.util.*;

public class Solution {
    public int[] solution(int[] nodes, int[][] edges) {
        // 그래프 인접 리스트
        Map<Integer, List<Integer>> graph = new HashMap<>();
        for (int n : nodes) {
            graph.put(n, new ArrayList<>()); // isolated node 보장
        }
        for (int[] e : edges) {
            int a = e[0], b = e[1];
            graph.get(a).add(b);
            graph.get(b).add(a);
        }

        Set<Integer> visited = new HashSet<>();
        int ansHol = 0;
        int ansRev = 0;

        for (int start : nodes) {
            if (visited.contains(start)) continue;

            // BFS로 컴포넌트 수집
            List<Integer> comp = new ArrayList<>();
            Queue<Integer> q = new ArrayDeque<>();
            q.add(start);
            visited.add(start);

            while (!q.isEmpty()) {
                int u = q.poll();
                comp.add(u);
                for (int v : graph.get(u)) {
                    if (!visited.contains(v)) {
                        visited.add(v);
                        q.add(v);
                    }
                }
            }

            int holNonrootCnt = 0; // 비-루트 가정에서 "홀짝" 노드 개수
            int revNonrootCnt = 0; // 비-루트 가정에서 "역홀짝" 노드 개수

            for (int u : comp) {
                int deg = graph.get(u).size();
                int nonrootChildren = deg - 1; // 비-루트일 때 자식 수
                if ((u % 2) == (nonrootChildren % 2)) {
                    holNonrootCnt++;
                } else {
                    revNonrootCnt++;
                }
            }

            if (revNonrootCnt == 1) ansHol++;
            if (holNonrootCnt == 1) ansRev++;
        }

        return new int[]{ansHol, ansRev};
    }
}