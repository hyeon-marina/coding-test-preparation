import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        for(int i=0; i<T; i++) {
            int x = sc.nextInt();
            int y = sc.nextInt();
            int d = y - x;
            int n = (int)Math.sqrt(d);
            if(n * n == d)
                System.out.println(2 * n - 1);
            else if(n * n < d && d <= n * (n + 1))
                System.out.println(2 * n);
            else
                System.out.println(2 * n + 1);
        }
    }
}
