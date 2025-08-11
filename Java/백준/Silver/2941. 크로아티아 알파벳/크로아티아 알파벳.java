import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] croatia = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};
        String input = br.readLine();

        for (String cro : croatia) {
            input = input.replace(cro, "*"); // 크로아티아 알파벳 부분을 '*'로 대체
        }

        System.out.println(input.length());
    }
}
