#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define MOD1 1000000007u
#define MOD2 1000000009u
#define BASE 911382323u

static uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15ULL;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9ULL;
    x = (x ^ (x >> 27)) * 0x94d049bb133111ebULL;
    return x ^ (x >> 31);
}

typedef struct {
    uint64_t *keys;
    unsigned char *used;
    size_t cap, size;
    size_t threshold;
} U64Set;

static void set_init(U64Set *st, size_t cap) {
    size_t c = 1;
    while (c < cap) c <<= 1;
    st->cap = c;
    st->size = 0;
    st->threshold = (size_t)(c * 0.7);
    st->keys = (uint64_t*)malloc(sizeof(uint64_t) * c);
    st->used = (unsigned char*)calloc(c, 1);
}

static void set_free(U64Set *st) {
    free(st->keys);
    free(st->used);
}

static void set_rehash(U64Set *st);

static void set_add(U64Set *st, uint64_t key) {
    if (st->size >= st->threshold) set_rehash(st);
    size_t mask = st->cap - 1;
    size_t i = (size_t)splitmix64(key) & mask;
    while (st->used[i]) {
        if (st->keys[i] == key) return;
        i = (i + 1) & mask;
    }
    st->used[i] = 1;
    st->keys[i] = key;
    st->size++;
}

static void set_rehash(U64Set *st) {
    U64Set nw;
    set_init(&nw, st->cap << 1);
    for (size_t i = 0; i < st->cap; i++) {
        if (st->used[i]) set_add(&nw, st->keys[i]);
    }
    free(st->keys);
    free(st->used);
    *st = nw;
}

int main(void) {
    char s[1005];
    if (!fgets(s, sizeof(s), stdin)) return 0;
    size_t n = strcspn(s, "\r\n");
    s[n] = '\0';

    uint32_t *pow1 = (uint32_t*)malloc(sizeof(uint32_t) * (n + 1));
    uint32_t *pow2 = (uint32_t*)malloc(sizeof(uint32_t) * (n + 1));
    uint32_t *pref1 = (uint32_t*)malloc(sizeof(uint32_t) * (n + 1));
    uint32_t *pref2 = (uint32_t*)malloc(sizeof(uint32_t) * (n + 1));

    pow1[0] = 1; pow2[0] = 1;
    pref1[0] = 0; pref2[0] = 0;

    for (size_t i = 0; i < n; i++) {
        uint32_t x = (unsigned char)s[i];
        pow1[i + 1] = (uint64_t)pow1[i] * BASE % MOD1;
        pow2[i + 1] = (uint64_t)pow2[i] * BASE % MOD2;
        pref1[i + 1] = ((uint64_t)pref1[i] * BASE + x) % MOD1;
        pref2[i + 1] = ((uint64_t)pref2[i] * BASE + x) % MOD2;
    }

    U64Set set;
    set_init(&set, 1 << 20);

    for (size_t l = 0; l < n; l++) {
        for (size_t r = l + 1; r <= n; r++) {
            size_t len = r - l;

            uint32_t h1 = (pref1[r] + MOD1 - (uint64_t)pref1[l] * pow1[len] % MOD1) % MOD1;
            uint32_t h2 = (pref2[r] + MOD2 - (uint64_t)pref2[l] * pow2[len] % MOD2) % MOD2;

            uint64_t key = ((uint64_t)len << 40) ^ ((uint64_t)h1 << 20) ^ (uint64_t)h2;
            set_add(&set, key);
        }
    }

    printf("%zu\n", set.size);

    set_free(&set);
    free(pow1); free(pow2); free(pref1); free(pref2);
    return 0;
}
