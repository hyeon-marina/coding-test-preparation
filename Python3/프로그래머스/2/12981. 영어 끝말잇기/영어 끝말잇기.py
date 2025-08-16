def solution(n, words):
    used = set()
    prev_last_char = None

    for i, word in enumerate(words):
        # 차례 계산
        person = (i % n) + 1
        turn = (i // n) + 1

        # 탈락 조건: 이미 사용된 단어 또는 첫 글자가 이전 단어 끝과 다름 또는 단어 길이 < 2
        if word in used or (prev_last_char is not None and word[0] != prev_last_char) or len(word) < 2:
            return [person, turn]

        # 정상 진행
        used.add(word)
        prev_last_char = word[-1]

    return [0, 0]