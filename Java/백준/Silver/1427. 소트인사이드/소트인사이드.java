import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Arrays;
import java.util.Collections;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String n = br.readLine().trim();
        Character[] arr = new Character[n.length()];
        for (int i = 0; i < n.length(); i++) {
            arr[i] = n.charAt(i);
        }
        Arrays.sort(arr, Collections.reverseOrder());
        StringBuilder sb = new StringBuilder();
        for (Character c : arr) {
            sb.append(c);
        }
        System.out.println(sb.toString());
    }
}