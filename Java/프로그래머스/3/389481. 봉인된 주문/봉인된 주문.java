import java.util.*;

public class Solution {
    static final int MAX_L = 11;
    static final int ALPH = 26;
    static long[] pow26 = new long[MAX_L + 1];
    
    public String solution(long n, String[] bans) {
        // pow26 준비
        pow26[0] = 1;
        for (int i = 1; i <= MAX_L; i++) {
            pow26[i] = pow26[i-1] * ALPH;
        }
        // bans 문자열 → 인덱스
        long[] banIdx = new long[bans.length];
        for (int i = 0; i < bans.length; i++) {
            banIdx[i] = strToIdx(bans[i]);
        }
        Arrays.sort(banIdx);
        
        long lo = 1;
        long hi = 0;
        for (int i = 1; i <= MAX_L; i++) {
            hi += pow26[i];
        }
        
        while (lo < hi) {
            long mid = lo + (hi - lo) / 2;
            // ban 중 ≤ mid 개수 구하기
            int cnt = upperBound(banIdx, mid);
            long effective = mid - cnt;
            if (effective < n) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        
        String ans = idxToStr(lo);
        // ans 가 삭제된 문자열이면 다음 유효한 문자열로
        Set<String> banSet = new HashSet<>(Arrays.asList(bans));
        while (banSet.contains(ans)) {
            lo++;
            ans = idxToStr(lo);
        }
        return ans;
    }
    
    private long strToIdx(String s) {
        int l = s.length();
        long tot = 0;
        for (int i = 1; i < l; i++) {
            tot += pow26[i];
        }
        long val = 0;
        for (int i = 0; i < l; i++) {
            val = val * ALPH + (s.charAt(i) - 'a');
        }
        return tot + val + 1;
    }
    
    private String idxToStr(long idx) {
        long tot = 0;
        int l = 1;
        for (; l <= MAX_L; l++) {
            if (tot + pow26[l] >= idx) break;
            tot += pow26[l];
        }
        if (l > MAX_L) l = MAX_L; // 안전 처리
        long offset = idx - tot - 1;
        char[] buf = new char[l];
        for (int i = l - 1; i >= 0; i--) {
            buf[i] = (char)('a' + (int)(offset % ALPH));
            offset /= ALPH;
        }
        return new String(buf);
    }
    
    // upper bound: bans 정렬된 배열에서 ≤ target 인 요소 개수
    private int upperBound(long[] arr, long target) {
        int lo = 0, hi = arr.length;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (arr[mid] <= target) lo = mid + 1;
            else hi = mid;
        }
        return lo;
    }
}