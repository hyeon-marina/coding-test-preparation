def solution(heights):
    heights.sort()
    n = len(heights)
    # 짝수 개수일 경우
    if n % 2 == 0:
        # 절반 나눠서 비교
        half = n // 2
        diffs = []
        for i in range(half):
            diffs.append(heights[i + half] - heights[i])
        return min(diffs)
    else:
        # 홀수 개수일 경우
        half = n // 2
        diffs = []
        # 가장 큰 값을 제외한 나머지 절반씩 비교
        for i in range(half):
            diffs.append(heights[i + half] - heights[i])
        # 그리고 가장 큰 값과 중앙값(절반 인덱스)의 값 차이도 고려
        diffs.append(heights[-1] - heights[half])
        # diffs 정렬하고 두 번째로 작은 값 선택
        diffs.sort()
        return diffs[1]