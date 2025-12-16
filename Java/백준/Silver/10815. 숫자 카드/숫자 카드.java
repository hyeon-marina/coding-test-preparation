import java.io.*;
import java.util.*;

public class Main {
    static int lowerBound(int[] a, int x) {
        int l = 0, r = a.length;
        while (l < r) {
            int mid = (l + r) >>> 1;
            if (a[mid] >= x) r = mid;
            else l = mid + 1;
        }
        return l;
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        int n = Integer.parseInt(br.readLine().trim());
        int[] cards = new int[n];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) cards[i] = Integer.parseInt(st.nextToken());
        Arrays.sort(cards);

        int m = Integer.parseInt(br.readLine().trim());
        st = new StringTokenizer(br.readLine());
        StringBuilder sb = new StringBuilder();

        for (int i = 0; i < m; i++) {
            int x = Integer.parseInt(st.nextToken());
            int idx = lowerBound(cards, x);
            if (idx < n && cards[idx] == x) sb.append('1');
            else sb.append('0');
            if (i + 1 < m) sb.append(' ');
        }
        System.out.print(sb.toString());
    }
}
