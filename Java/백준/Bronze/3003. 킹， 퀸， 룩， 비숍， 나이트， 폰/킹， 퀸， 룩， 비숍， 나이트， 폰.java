import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        int[] goal = {1, 1, 2, 2, 2, 8};
        Scanner sc = new Scanner(System.in);
        for (int i = 0; i < goal.length; i++) {
            int x = sc.nextInt();
            System.out.print((goal[i] - x) + " ");
        }
        sc.close();
    }
}