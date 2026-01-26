import java.io.*;
import java.util.*;

public class Main {
    static final int MOD1 = 1_000_000_007;
    static final int MOD2 = 1_000_000_009;
    static final int BASE = 911382323;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = br.readLine().trim();
        int n = s.length();

        long[] pow1 = new long[n + 1];
        long[] pow2 = new long[n + 1];
        long[] pref1 = new long[n + 1];
        long[] pref2 = new long[n + 1];

        pow1[0] = 1; pow2[0] = 1;
        for (int i = 0; i < n; i++) {
            int x = s.charAt(i);
            pow1[i + 1] = (pow1[i] * BASE) % MOD1;
            pow2[i + 1] = (pow2[i] * BASE) % MOD2;
            pref1[i + 1] = (pref1[i] * BASE + x) % MOD1;
            pref2[i + 1] = (pref2[i] * BASE + x) % MOD2;
        }

        LongHashSet set = new LongHashSet(1 << 20); // 초기 용량 넉넉히

        for (int l = 0; l < n; l++) {
            for (int r = l + 1; r <= n; r++) {
                int len = r - l;

                long h1 = (pref1[r] - (pref1[l] * pow1[len]) % MOD1 + MOD1) % MOD1;
                long h2 = (pref2[r] - (pref2[l] * pow2[len]) % MOD2 + MOD2) % MOD2;

                long key = (((long)len) << 48) ^ (h1 << 24) ^ h2; // len 포함 (충돌 완화)
                set.add(key);
            }
        }

        System.out.print(set.size());
    }

    // primitive long hash set (open addressing)
    static class LongHashSet {
        private long[] table;
        private boolean[] used;
        private int size, mask, threshold;

        LongHashSet(int capacity) {
            int cap = 1;
            while (cap < capacity) cap <<= 1;
            table = new long[cap];
            used = new boolean[cap];
            mask = cap - 1;
            threshold = (int)(cap * 0.7);
        }

        int size() { return size; }

        void add(long x) {
            if (size >= threshold) rehash();
            int i = mix64To32(x) & mask;
            while (used[i]) {
                if (table[i] == x) return;
                i = (i + 1) & mask;
            }
            used[i] = true;
            table[i] = x;
            size++;
        }

        private void rehash() {
            long[] oldT = table;
            boolean[] oldU = used;
            int newCap = oldT.length << 1;
            table = new long[newCap];
            used = new boolean[newCap];
            mask = newCap - 1;
            threshold = (int)(newCap * 0.7);
            size = 0;

            for (int i = 0; i < oldT.length; i++) {
                if (oldU[i]) add(oldT[i]);
            }
        }

        private static int mix64To32(long z) {
            z ^= (z >>> 33);
            z *= 0xff51afd7ed558ccdL;
            z ^= (z >>> 33);
            z *= 0xc4ceb9fe1a85ec53L;
            z ^= (z >>> 33);
            return (int)z;
        }
    }
}
