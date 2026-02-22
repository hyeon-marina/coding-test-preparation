import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        long n = Long.parseLong(br.readLine().trim());
        long ans = (long)Math.sqrt(n);
        while ((ans + 1) * (ans + 1) <= n) ans++;
        while (ans * ans > n) ans--;
        System.out.println(ans);
    }
}