import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line = br.readLine().trim();
        long n = Long.parseLong(line);
        long count = n * (n - 1) * (n - 2) / 6;
        System.out.println(count);
        System.out.println(3);
    }
}