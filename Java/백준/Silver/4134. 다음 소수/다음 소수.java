import java.io.*;
import java.math.BigInteger;

public class Main {
    static final long[] BASES = {2, 3, 5, 7, 11, 13, 17};

    static boolean isPrime(long n) {
        if (n < 2) return false;
        long[] small = {2,3,5,7,11,13,17,19,23,29,31,37};
        for (long p : small) {
            if (n == p) return true;
            if (n % p == 0) return false;
        }

        long d = n - 1;
        int s = 0;
        while ((d & 1) == 0) {
            d >>= 1;
            s++;
        }

        BigInteger nBI = BigInteger.valueOf(n);
        BigInteger dBI = BigInteger.valueOf(d);

        for (long a : BASES) {
            if (a % n == 0) continue;
            BigInteger x = BigInteger.valueOf(a).modPow(dBI, nBI);
            if (x.equals(BigInteger.ONE) || x.equals(nBI.subtract(BigInteger.ONE))) continue;

            boolean composite = true;
            for (int r = 1; r < s; r++) {
                x = x.multiply(x).mod(nBI);
                if (x.equals(nBI.subtract(BigInteger.ONE))) {
                    composite = false;
                    break;
                }
            }
            if (composite) return false;
        }
        return true;
    }

    static long nextPrime(long n) {
        if (n <= 2) return 2;
        if ((n & 1) == 0) n++;
        while (!isPrime(n)) n += 2;
        return n;
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int t = Integer.parseInt(br.readLine().trim());
        for (int i = 0; i < t; i++) {
            long n = Long.parseLong(br.readLine().trim());
            sb.append(nextPrime(n)).append('\n');
        }
        System.out.print(sb.toString());
    }
}
