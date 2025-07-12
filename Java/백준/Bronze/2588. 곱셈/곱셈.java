import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int A = sc.nextInt();
        int B = sc.nextInt();

        int ones = B % 10;           // 1의 자리
        int tens = (B / 10) % 10;    // 10의 자리
        int hundreds = B / 100;      // 100의 자리

        System.out.println(A * ones);
        System.out.println(A * tens);
        System.out.println(A * hundreds);
        System.out.println(A * B);

        sc.close();
    }
}
