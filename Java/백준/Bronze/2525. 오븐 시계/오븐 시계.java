import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        int c = sc.nextInt();

        int totalMinutes = a * 60 + b + c;
        int hour = (totalMinutes / 60) % 24;
        int minute = totalMinutes % 60;

        System.out.println(hour + " " + minute);
    }
}
