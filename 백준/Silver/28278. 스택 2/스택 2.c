#include <stdio.h>

int stack[1000000];
int top = -1;

int main() {
    int n;
    scanf("%d", &n);

    while (n--) {
        int op;
        scanf("%d", &op);

        if (op == 1) {
            int x;
            scanf("%d", &x);
            stack[++top] = x;
        } else if (op == 2) {
            if (top == -1) printf("-1\n");
            else printf("%d\n", stack[top--]);
        } else if (op == 3) {
            printf("%d\n", top + 1);
        } else if (op == 4) {
            printf("%d\n", top == -1 ? 1 : 0);
        } else if (op == 5) {
            if (top == -1) printf("-1\n");
            else printf("%d\n", stack[top]);
        }
    }

    return 0;
}