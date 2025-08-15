import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int X = sc.nextInt();
        int line = 1;
        while (X > line) {
            X -= line;
            line++;
        }
        int a, b;
        if (line % 2 == 0) {
            a = X;
            b = line - X + 1;
        } else {
            a = line - X + 1;
            b = X;
        }
        System.out.println(a + "/" + b);
    }
}
