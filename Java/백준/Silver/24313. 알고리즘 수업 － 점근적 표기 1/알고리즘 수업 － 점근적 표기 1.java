import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] parts = br.readLine().split(" ");
        int a1 = Integer.parseInt(parts[0]);
        int a0 = Integer.parseInt(parts[1]);
        int c = Integer.parseInt(br.readLine().trim());
        int n0 = Integer.parseInt(br.readLine().trim());

        if (a1 <= c && (long)a1 * n0 + a0 <= (long)c * n0) {
            System.out.println(1);
        } else {
            System.out.println(0);
        }
    }
}