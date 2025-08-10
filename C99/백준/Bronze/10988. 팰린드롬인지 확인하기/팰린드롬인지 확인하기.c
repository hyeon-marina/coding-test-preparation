#include <stdio.h>
#include <string.h>

int main() {
    char word[101];  // 최대 100자 + null terminator
    scanf("%s", word);
    
    int len = strlen(word);
    int isPalindrome = 1;  // 1: 팰린드롬, 0: 팰린드롬 아님
    
    // 팰린드롬 확인
    for (int i = 0; i < len / 2; i++) {
        if (word[i] != word[len - 1 - i]) {
            isPalindrome = 0;
            break;
        }
    }
    
    // 결과 출력
    printf("%d\n", isPalindrome);
    
    return 0;
}