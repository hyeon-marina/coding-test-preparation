import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine().trim());

        int count5 = n / 5;
        while (count5 >= 0) {
            int rem = n - count5 * 5;
            if (rem % 3 == 0) {
                int count3 = rem / 3;
                System.out.println(count5 + count3);
                return;
            }
            count5--;
        }
        System.out.println(-1);
    }
}