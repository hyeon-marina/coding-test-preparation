import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for (int i = 0; i < t; i++) {
            int c = sc.nextInt();
            System.out.print(c/25 + " ");
            c %= 25;
            System.out.print(c/10 + " ");
            c %= 10;
            System.out.print(c/5 + " ");
            c %= 5;
            System.out.println(c);
        }
    }
}
