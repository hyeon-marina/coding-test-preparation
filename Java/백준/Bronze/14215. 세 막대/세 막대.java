import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int a = Integer.parseInt(st.nextToken());
        int b = Integer.parseInt(st.nextToken());
        int c = Integer.parseInt(st.nextToken());
        int[] s = {a, b, c};
        Arrays.sort(s);
        int x = s[0], y = s[1], z = s[2];

        int result;
        if (x + y > z) {
            result = x + y + z;
        } else {
            result = 2 * (x + y) - 1;
        }

        System.out.println(result);
    }
}