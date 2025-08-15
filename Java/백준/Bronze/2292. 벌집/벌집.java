import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int honey = 1;
        int layer = 1;
        while (n > honey) {
            honey += 6 * layer;
            layer++;
        }
        System.out.println(layer);
    }
}
