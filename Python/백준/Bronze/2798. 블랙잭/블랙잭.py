import sys
input = sys.stdin.readline

def solve():
    N, M = map(int, input().split())
    cards = list(map(int, input().split()))
    best = 0
    # 세 장을 고르는 모든 조합 탐색
    for i in range(N - 2):
        for j in range(i + 1, N - 1):
            for k in range(j + 1, N):
                s = cards[i] + cards[j] + cards[k]
                if s <= M and s > best:
                    best = s
                # 만약 정확히 M이면 더 이상 클 수 없으므로 조기 종료 가능
                if best == M:
                    print(M)
                    return
    print(best)

if __name__ == "__main__":
    solve()