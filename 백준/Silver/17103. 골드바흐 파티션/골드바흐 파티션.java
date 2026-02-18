import java.io.*;
import java.util.*;

public class Main {
    static boolean[] sieve(int n) {
        boolean[] isPrime = new boolean[n + 1];
        Arrays.fill(isPrime, true);
        if (n >= 0) isPrime[0] = false;
        if (n >= 1) isPrime[1] = false;

        int limit = (int)Math.sqrt(n);
        for (int i = 2; i <= limit; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= n; j += i) {
                    isPrime[j] = false;
                }
            }
        }
        return isPrime;
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine().trim());
        int[] nums = new int[t];
        int maxN = 0;
        for (int i = 0; i < t; i++) {
            nums[i] = Integer.parseInt(br.readLine().trim());
            if (nums[i] > maxN) maxN = nums[i];
        }

        boolean[] isPrime = sieve(maxN);

        StringBuilder sb = new StringBuilder();
        for (int n : nums) {
            int cnt = 0;
            int half = n / 2;
            for (int p = 2; p <= half; p++) {
                if (isPrime[p] && isPrime[n - p]) cnt++;
            }
            sb.append(cnt).append('\n');
        }
        System.out.print(sb.toString());
    }
}
