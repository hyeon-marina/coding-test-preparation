import bisect

def solution(n, bans):
    MAX_L = 11
    ALPH = 26

    pow26 = [1] * (MAX_L + 1)
    for i in range(1, MAX_L + 1):
        pow26[i] = pow26[i-1] * ALPH

    # 문자열 → 인덱스 (1-based)
    def str_to_idx(s: str) -> int:
        l = len(s)
        tot = sum(pow26[1:l])  # 길이 l 미만 문자열 개수
        val = 0
        for ch in s:
            val = val * ALPH + (ord(ch) - ord('a'))
        return tot + val + 1

    # 인덱스 → 문자열
    def idx_to_str(idx: int) -> str:
        tot = 0
        for l in range(1, MAX_L + 1):
            if tot + pow26[l] >= idx:
                break
            tot += pow26[l]
        offset = idx - tot - 1
        chars = []
        for _ in range(l):
            chars.append(chr(ord('a') + (offset % ALPH)))
            offset //= ALPH
        return "".join(reversed(chars))

    ban_indices = [str_to_idx(b) for b in bans]
    ban_indices.sort()

    total_strings = sum(pow26[1:])  # 전체 문자열 수

    lo, hi = 1, total_strings
    while lo < hi:
        mid = (lo + hi) // 2
        cnt_bans = bisect.bisect_right(ban_indices, mid)
        effective = mid - cnt_bans
        if effective < n:
            lo = mid + 1
        else:
            hi = mid

    return idx_to_str(lo)