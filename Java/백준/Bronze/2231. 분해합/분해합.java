import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class Main {
    static int selfSum(int x) {
        int s = x;
        while (x > 0) {
            s += x % 10;
            x /= 10;
        }
        return s;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine().trim());
        int ans = 0;

        int d = String.valueOf(N).length();
        int start = Math.max(1, N - 9 * d);
        for (int m = start; m < N; m++) {
            if (selfSum(m) == N) {
                ans = m;
                break;
            }
        }
        System.out.println(ans);
    }
}