def solution(n, bans):
    from bisect import bisect_left
    # bans를 길이별로 분류하고 정렬
    by_len = {}
    for b in bans:
        by_len.setdefault(len(b), []).append(b)
    for k in by_len:
        by_len[k].sort()

    # 1) 전체 길이별 가능 수와 삭제 수로 n 위치 조정
    L = 1
    remain = n
    while True:
        total = 26 ** L
        removed = len(by_len.get(L, []))
        if remain <= total - removed:
            break
        remain -= (total - removed)
        L += 1

    # 2) 삭제된 문자열이 lexicographically 이전인 개수 계산
    ban_list = by_len.get(L, [])
    cnt_before = bisect_left(ban_list, "")  # 빈 문자열은 placeholder
    # 대신 밴 리스트 내 문자열을 하나씩 비교
    cnt_before = 0
    for b in ban_list:
        # b가 전체 범위 내에서 remain보다 앞선다면 제외해서 remain 증가
        idx = sum(26 ** (L - i - 1) * (ord(b[i]) - ord('a')) for i in range(L)) + 1
        if idx <= remain + cnt_before:
            cnt_before += 1

    target_idx = remain + cnt_before - 1  # 0-based 인덱스

    # 3) target_idx에 해당하는 문자열 생성
    res = []
    for _ in range(L):
        div, target_idx = divmod(target_idx, 26 ** (L - len(res) - 1))
        res.append(chr(ord('a') + div))
    return ''.join(res)