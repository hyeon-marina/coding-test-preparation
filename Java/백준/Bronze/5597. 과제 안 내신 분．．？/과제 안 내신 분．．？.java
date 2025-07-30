import java.util.Scanner;

public class Main {
    public static void main(String[] args){
        int[] arr = new int[31]; // 1~30번이므로 인덱스 1~30까지 사용
        Scanner sc = new Scanner(System.in);
        for(int i=0; i<28; i++){
            int num = sc.nextInt();
            arr[num] = 1; // 숙제 제출자 번호를 체크
        }
        for(int i=1; i<=30; i++){
            if(arr[i] == 0) // 제출하지 않은 학생
                System.out.println(i);
        }
        sc.close();
    }
}
