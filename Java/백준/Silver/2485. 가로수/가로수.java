import java.io.*;
import java.util.*;

public class Main {
    static int gcd(int a, int b) {
        while (b != 0) {
            int t = a % b;
            a = b;
            b = t;
        }
        return a;
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine().trim());

        int[] pos = new int[n];
        for (int i = 0; i < n; i++) pos[i] = Integer.parseInt(br.readLine().trim());
        Arrays.sort(pos);

        int[] diffs = new int[n - 1];
        for (int i = 1; i < n; i++) diffs[i - 1] = pos[i] - pos[i - 1];

        int g = diffs[0];
        for (int i = 1; i < diffs.length; i++) g = gcd(g, diffs[i]);

        long ans = 0;
        for (int d : diffs) ans += (d / g) - 1;

        System.out.println(ans);
    }
}
