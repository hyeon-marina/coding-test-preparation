import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        boolean[] check = new boolean[42];
        Scanner sc = new Scanner(System.in);
        for (int i = 0; i < 10; i++) {
            check[sc.nextInt() % 42] = true;
        }
        int count = 0;
        for (boolean c : check) {
            if (c) count++;
        }
        System.out.println(count);
        sc.close();
    }
}
