N = int(input())
group_word_count = N

for _ in range(N):
    word = input()
    for i in range(len(word) - 1):
        if word[i] == word[i + 1]:
            continue
        elif word[i] in word[i + 1:]:
            group_word_count -= 1
            break

print(group_word_count)
