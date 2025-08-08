import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        String a = st.nextToken();
        String b = st.nextToken();

        int a_rev = Integer.parseInt(new StringBuilder(a).reverse().toString());
        int b_rev = Integer.parseInt(new StringBuilder(b).reverse().toString());

        System.out.println(Math.max(a_rev, b_rev));
    }
}
