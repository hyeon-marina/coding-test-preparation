import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int buddhistYear = sc.nextInt();
        int gregorianYear = buddhistYear - 543;
        System.out.println(gregorianYear);
    }
}
