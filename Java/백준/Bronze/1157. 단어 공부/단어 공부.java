import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int[] frequency = new int[26];
        String word = br.readLine();

        for (int i = 0; i < word.length(); i++) {
            char ch = Character.toUpperCase(word.charAt(i));
            frequency[ch - 'A']++;
        }

        int maxFreq = -1;
        char maxChar = '?';
        boolean isMultiple = false;

        for (int i = 0; i < 26; i++) {
            if (frequency[i] > maxFreq) {
                maxFreq = frequency[i];
                maxChar = (char) (i + 'A');
                isMultiple = false;
            } else if (frequency[i] == maxFreq) {
                isMultiple = true;
            }
        }

        System.out.println(isMultiple ? "?" : maxChar);
    }
}
