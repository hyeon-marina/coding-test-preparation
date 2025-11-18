import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine().trim());
        StringTokenizer st = new StringTokenizer(br.readLine());
        int[] arr = new int[N];
        for(int i=0;i<N;i++){
            arr[i] = Integer.parseInt(st.nextToken());
        }

        int[] sorted = arr.clone();
        Arrays.sort(sorted);

        // 중복 제거 + 인덱스 매핑
        Map<Integer,Integer> map = new HashMap<>();
        int idx = 0;
        map.put(sorted[0], idx);
        for(int i=1;i<N;i++){
            if(sorted[i] != sorted[i-1]){
                idx++;
                map.put(sorted[i], idx);
            }
        }

        StringBuilder sb = new StringBuilder();
        for(int i=0;i<N;i++){
            sb.append(map.get(arr[i])).append(' ');
        }
        System.out.println(sb.toString().trim());
    }
}