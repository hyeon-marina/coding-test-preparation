#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 21
#define TABLE_SIZE 262139

typedef struct Node {
    char key[MAX_NAME];
    int val;
    struct Node *next;
} Node;

static Node* table[TABLE_SIZE];

unsigned int hash_str(const char *s) {
    // djb2
    unsigned long h = 5381;
    int c;
    while ((c = *s++)) h = ((h << 5) + h) + (unsigned long)c;
    return (unsigned int)(h % TABLE_SIZE);
}

void put(const char *key, int val) {
    unsigned int h = hash_str(key);
    Node *node = (Node*)malloc(sizeof(Node));
    strcpy(node->key, key);
    node->val = val;
    node->next = table[h];
    table[h] = node;
}

int get(const char *key) {
    unsigned int h = hash_str(key);
    Node *cur = table[h];
    while (cur) {
        if (strcmp(cur->key, key) == 0) return cur->val;
        cur = cur->next;
    }
    return -1;
}

int is_number(const char *s) {
    if (*s == '\0') return 0;
    for (int i = 0; s[i]; i++) {
        if (s[i] < '0' || s[i] > '9') return 0;
    }
    return 1;
}

int main(void) {
    int n, m;
    scanf("%d %d", &n, &m);

    char **numToName = (char**)malloc((n + 1) * sizeof(char*));
    for (int i = 1; i <= n; i++) {
        numToName[i] = (char*)malloc(MAX_NAME);
        scanf("%20s", numToName[i]);
        put(numToName[i], i);
    }

    char q[32];
    for (int i = 0; i < m; i++) {
        scanf("%31s", q);
        if (is_number(q)) {
            int idx = atoi(q);
            puts(numToName[idx]);
        } else {
            int idx = get(q);
            printf("%d\n", idx);
        }
    }

    for (int i = 1; i <= n; i++) free(numToName[i]);
    free(numToName);

    for (int i = 0; i < TABLE_SIZE; i++) {
        Node *cur = table[i];
        while (cur) {
            Node *nxt = cur->next;
            free(cur);
            cur = nxt;
        }
    }
    return 0;
}
