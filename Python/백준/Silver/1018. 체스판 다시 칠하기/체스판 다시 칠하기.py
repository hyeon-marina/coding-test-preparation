import sys
input = sys.stdin.readline

N, M = map(int, input().split())
board = [input().rstrip() for _ in range(N)]

def count_repaint(sy, sx):
    cnt1 = 0  # W 시작 무늬로 맞출 경우
    cnt2 = 0  # B 시작 무늬로 맞출 경우
    for i in range(8):
        for j in range(8):
            current = board[sy + i][sx + j]
            if (i + j) % 2 == 0:
                # 이 칸은 시작 색과 같아야 함
                if current != 'W':
                    cnt1 += 1
                if current != 'B':
                    cnt2 += 1
            else:
                # 이 칸은 시작 색과 반대여야 함
                if current != 'B':
                    cnt1 += 1
                if current != 'W':
                    cnt2 += 1
    return min(cnt1, cnt2)

ans = float('inf')
for i in range(N - 7):
    for j in range(M - 7):
        ans = min(ans, count_repaint(i, j))

print(ans)