import java.io.*;
import java.util.*;

public class Main {
    static int[] sievePrefix(int limit) {
        boolean[] isPrime = new boolean[limit + 1];
        Arrays.fill(isPrime, true);
        if (limit >= 0) isPrime[0] = false;
        if (limit >= 1) isPrime[1] = false;

        for (int p = 2; p * p <= limit; p++) {
            if (isPrime[p]) {
                for (int x = p * p; x <= limit; x += p) {
                    isPrime[x] = false;
                }
            }
        }

        int[] prefix = new int[limit + 1];
        int cnt = 0;
        for (int i = 0; i <= limit; i++) {
            if (isPrime[i]) cnt++;
            prefix[i] = cnt;
        }
        return prefix;
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        ArrayList<Integer> queries = new ArrayList<>();
        int maxN = 0;

        while (true) {
            String line = br.readLine();
            if (line == null) break;
            line = line.trim();
            if (line.isEmpty()) continue;
            int n = Integer.parseInt(line);
            if (n == 0) break;
            queries.add(n);
            if (n > maxN) maxN = n;
        }

        if (queries.isEmpty()) return;

        int limit = 2 * maxN;
        int[] prefix = sievePrefix(limit);

        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < queries.size(); i++) {
            int n = queries.get(i);
            int ans = prefix[2 * n] - prefix[n];
            sb.append(ans);
            if (i + 1 < queries.size()) sb.append('\n');
        }
        System.out.print(sb.toString());
    }
}
