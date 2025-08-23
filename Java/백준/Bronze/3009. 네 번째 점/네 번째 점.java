import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int x4 = 0, y4 = 0;
        for (int i = 0; i < 3; i++) {
            x4 ^= sc.nextInt();
            y4 ^= sc.nextInt();
        }
        System.out.println(x4 + " " + y4);
    }
}