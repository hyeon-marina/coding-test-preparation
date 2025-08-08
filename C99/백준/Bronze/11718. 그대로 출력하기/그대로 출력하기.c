#include <stdio.h>

int main() {
    char line[101];
    while (fgets(line, sizeof(line), stdin)) {
        printf("%s", line);
    }
    return 0;
}
