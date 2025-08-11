#include <stdio.h>
#include <string.h>

int main() {
    int N, group_word_count = 0;
    scanf("%d", &N);
    char word[101];

    for (int i = 0; i < N; i++) {
        scanf("%s", word);
        int alphabet[26] = {0};
        int len = strlen(word);
        int is_group_word = 1;

        for (int j = 0; j < len; j++) {
            int index = word[j] - 'a';
            if (alphabet[index] == 0) {
                alphabet[index] = 1;
            } else {
                if (word[j] != word[j - 1]) {
                    is_group_word = 0;
                    break;
                }
            }
        }

        if (is_group_word) {
            group_word_count++;
        }
    }

    printf("%d\n", group_word_count);
    return 0;
}
