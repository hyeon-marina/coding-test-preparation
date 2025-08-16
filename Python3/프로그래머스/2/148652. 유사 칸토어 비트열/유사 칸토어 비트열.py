def solution(n, l, r):
    def count_one(n, k):
        if k <= 0:
            return 0
        if n == 0:
            return 1  # 길이 1의 "1"에서 k>=1이면 1

        part_len = 5 ** (n - 1)      # 각 구간 길이
        ones_per = 4 ** (n - 1)      # f(n-1) 내 1의 개수
        zone = (k - 1) // part_len   # 0~4
        t = k - zone * part_len      # 현재 구간 내 길이

        # 구간별 '완전히 지난' 구간의 1 개수 합: [0,1,2,2,3] * ones_per
        prefix = [0, 1, 2, 2, 3][zone] * ones_per
        if zone == 2:                # 중앙(0만 있는) 구간은 추가 없음
            return prefix
        return prefix + count_one(n - 1, t)

    return count_one(n, r) - count_one(n, l - 1)