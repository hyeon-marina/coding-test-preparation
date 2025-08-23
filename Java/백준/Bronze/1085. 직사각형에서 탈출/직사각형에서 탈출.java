import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] parts = br.readLine().split(" ");
        int x = Integer.parseInt(parts[0]);
        int y = Integer.parseInt(parts[1]);
        int w = Integer.parseInt(parts[2]);
        int h = Integer.parseInt(parts[3]);

        int min = Math.min(x, w - x);
        min = Math.min(min, y);
        min = Math.min(min, h - y);

        System.out.println(min);
    }
}