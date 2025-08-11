#include <stdio.h>
#include <ctype.h>

int main() {
    char word[1000001];
    int frequency[26] = {0};

    scanf("%s", word);

    for (int i = 0; word[i]; i++) {
        char ch = toupper(word[i]);
        frequency[ch - 'A']++;
    }

    int maxFreq = 0;
    int maxIndex = -1;
    int multiple = 0;

    for (int i = 0; i < 26; i++) {
        if (frequency[i] > maxFreq) {
            maxFreq = frequency[i];
            maxIndex = i;
            multiple = 0;
        } else if (frequency[i] == maxFreq) {
            multiple = 1;
        }
    }

    if (multiple) {
        printf("?\n");
    } else {
        printf("%c\n", maxIndex + 'A');
    }

    return 0;
}
