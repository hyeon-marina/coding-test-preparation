def solution(n, a, b):
    round_count = 0
    while a != b:
        a = (a + 1) // 2
        b = (b + 1) // 2
        round_count += 1
    return round_count
