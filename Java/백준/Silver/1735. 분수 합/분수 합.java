import java.io.*;
import java.util.*;

public class Main {
    static long gcd(long a, long b) {
        while (b != 0) {
            long t = a % b;
            a = b;
            b = t;
        }
        return a;
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());
        long a = Long.parseLong(st.nextToken());
        long b = Long.parseLong(st.nextToken());

        st = new StringTokenizer(br.readLine());
        long c = Long.parseLong(st.nextToken());
        long d = Long.parseLong(st.nextToken());

        long num = a * d + c * b;
        long den = b * d;

        long g = gcd(num, den);
        System.out.println((num / g) + " " + (den / g));
    }
}
