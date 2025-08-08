import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String word = br.readLine();
        int time = 0;

        for (int i = 0; i < word.length(); i++) {
            char c = word.charAt(i);
            if (c >= 'A' && c <= 'C') time += 3;
            else if (c >= 'D' && c <= 'F') time += 4;
            else if (c >= 'G' && c <= 'I') time += 5;
            else if (c >= 'J' && c <= 'L') time += 6;
            else if (c >= 'M' && c <= 'O') time += 7;
            else if (c >= 'P' && c <= 'S') time += 8;
            else if (c >= 'T' && c <= 'V') time += 9;
            else if (c >= 'W' && c <= 'Z') time += 10;
        }

        System.out.println(time);
    }
}
