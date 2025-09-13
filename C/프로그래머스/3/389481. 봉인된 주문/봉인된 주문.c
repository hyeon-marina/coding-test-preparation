#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define MAX_BANS 300000
#define MAX_L 11
#define ALPH 26

uint64_t pow26[MAX_L+1];

// compare for qsort for uint64_t
int cmp_uint64(const void *a, const void *b) {
    uint64_t va = *(const uint64_t*)a;
    uint64_t vb = *(const uint64_t*)b;
    if (va < vb) return -1;
    else if (va > vb) return 1;
    else return 0;
}

uint64_t str_to_idx(const char *s) {
    int l = strlen(s);
    uint64_t tot = 0;
    for (int i = 1; i < l; i++) {
        tot += pow26[i];
    }
    uint64_t val = 0;
    for (int i = 0; i < l; i++) {
        val = val * ALPH + (uint64_t)(s[i] - 'a');
    }
    // 1-based
    return tot + val + 1;
}

char *idx_to_str(uint64_t idx) {
    // find length l
    uint64_t tot = 0;
    int l;
    for (l = 1; l <= MAX_L; l++) {
        if (tot + pow26[l] >= idx) break;
        tot += pow26[l];
    }
    if (l > MAX_L) l = MAX_L;  // 안전장치
    uint64_t offset = idx - tot - 1;  // 0-based within length l

    // allocate string (길이 l + 널 종료자)
    char *s = malloc(l + 1);
    s[l] = '\0';
    for (int i = l-1; i >= 0; i--) {
        s[i] = (char)('a' + (offset % ALPH));
        offset /= ALPH;
    }
    return s;
}

char * solution(uint64_t n, char *bans[], int bans_len) {
    pow26[0] = 1;
    for (int i = 1; i <= MAX_L; i++) {
        pow26[i] = pow26[i-1] * ALPH;
    }

    // bans → indices
    uint64_t *ban_indices = malloc(sizeof(uint64_t) * bans_len);
    for (int i = 0; i < bans_len; i++) {
        ban_indices[i] = str_to_idx(bans[i]);
    }
    qsort(ban_indices, bans_len, sizeof(uint64_t), cmp_uint64);

    uint64_t lo = 1;
    uint64_t hi = 0;
    for (int i = 1; i <= MAX_L; i++) hi += pow26[i];

    while (lo < hi) {
        uint64_t mid = lo + (hi - lo) / 2;
        // count bans ≤ mid
        // 이진탐색 (자체 구현)
        int left = 0, right = bans_len;
        while (left < right) {
            int m = left + (right - left) / 2;
            if (ban_indices[m] <= mid) left = m + 1;
            else right = m;
        }
        uint64_t cnt_bans = left;
        uint64_t effective = mid - cnt_bans;
        if (effective < n) {
            lo = mid + 1;
        } else {
            hi = mid;
        }
    }

    // lo 가 원래 인덱스
    char *ans = idx_to_str(lo);

    // set of bans? 언어 C에서는 해시셋 구현하거나 정렬된 array + 이진탐색
    // 간단하게 정렬된 ban_indices와 비교하되 문자열 비교 필요.
    // 여기서는 번역된 문자열 ans 를 모든 bans와 비교하는 비효율적 방법 생략 가능.

    return ans;
}