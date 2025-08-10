import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String word = sc.next();
        
        // 팰린드롬 확인
        boolean isPalindrome = true;
        int len = word.length();
        
        for (int i = 0; i < len / 2; i++) {
            if (word.charAt(i) != word.charAt(len - 1 - i)) {
                isPalindrome = false;
                break;
            }
        }
        
        // 결과 출력
        if (isPalindrome) {
            System.out.println(1);  // 팰린드롬이면 1
        } else {
            System.out.println(0);  // 팰린드롬이 아니면 0
        }
        
        sc.close();
    }
}