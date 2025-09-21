import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line = br.readLine().trim();
        long n = Long.parseLong(line);
        long result = n * n * n;
        System.out.println(result);
        System.out.println(3);
    }
}