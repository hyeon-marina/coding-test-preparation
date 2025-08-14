import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long N = sc.nextLong();
        int B = sc.nextInt();
        String digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        StringBuilder sb = new StringBuilder();
        while (N > 0) {
            sb.append(digits.charAt((int)(N % B)));
            N /= B;
        }
        System.out.println(sb.reverse());
    }
}
