def solution(players, m, k):
    n = len(players)
    # 서버 반납 스케줄: t+k 시점에 반납될 서버 수 기록
    shut_down = [0] * (n + k)
    running = 0
    total_added = 0
    
    for t in range(n):
        # 반납 스케줄에 따라 서버 줄이기
        running -= shut_down[t]

        # 현재 시점에 필요한 서버 수
        required = players[t] // m

        if running < required:
            add = required - running
            total_added += add
            running += add
            # k시간 후 서버 반납 예정
            if t + k < len(shut_down):
                shut_down[t + k] += add

    return total_added