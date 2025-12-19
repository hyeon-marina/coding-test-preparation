#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int v;
    struct Node* next;
} Node;

static void add_edge(Node** adj, int a, int b) {
    Node* na = (Node*)malloc(sizeof(Node));
    na->v = b; na->next = adj[a]; adj[a] = na;

    Node* nb = (Node*)malloc(sizeof(Node));
    nb->v = a; nb->next = adj[b]; adj[b] = nb;
}

// Programmers signature style:
// int* solution(int n, int** roads, size_t roads_rows, size_t roads_cols,
//               int* sources, size_t sources_len, int destination)
int* solution(int n, int** roads, size_t roads_rows, size_t roads_cols,
              int* sources, size_t sources_len, int destination) {
    (void)roads_cols;

    Node** adj = (Node**)calloc((size_t)(n + 1), sizeof(Node*));
    for (size_t i = 0; i < roads_rows; i++) {
        int a = roads[i][0];
        int b = roads[i][1];
        add_edge(adj, a, b);
    }

    int* dist = (int*)malloc((size_t)(n + 1) * sizeof(int));
    for (int i = 0; i <= n; i++) dist[i] = -1;

    int* q = (int*)malloc((size_t)(n + 1) * sizeof(int));
    int head = 0, tail = 0;

    dist[destination] = 0;
    q[tail++] = destination;

    while (head < tail) {
        int cur = q[head++];
        for (Node* p = adj[cur]; p != NULL; p = p->next) {
            int nxt = p->v;
            if (dist[nxt] == -1) {
                dist[nxt] = dist[cur] + 1;
                q[tail++] = nxt;
            }
        }
    }

    int* ans = (int*)malloc(sources_len * sizeof(int));
    for (size_t i = 0; i < sources_len; i++) {
        ans[i] = dist[sources[i]];
    }

    // free adjacency list
    for (int i = 1; i <= n; i++) {
        Node* p = adj[i];
        while (p) {
            Node* tmp = p->next;
            free(p);
            p = tmp;
        }
    }
    free(adj);
    free(dist);
    free(q);

    return ans;
}
