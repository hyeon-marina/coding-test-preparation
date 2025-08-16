from collections import deque

def solution(maps):
    h = len(maps)
    w = len(maps[0])
    visited = [[False]*w for _ in range(h)]
    answer = []
    dirs = [(-1,0),(1,0),(0,-1),(0,1)]  # 상하좌우

    def bfs(sy, sx):
        q = deque([(sy, sx)])
        visited[sy][sx] = True
        total = int(maps[sy][sx])

        while q:
            y, x = q.popleft()
            for dy, dx in dirs:
                ny, nx = y + dy, x + dx
                if 0 <= ny < h and 0 <= nx < w:
                    if not visited[ny][nx] and maps[ny][nx] != 'X':
                        visited[ny][nx] = True
                        total += int(maps[ny][nx])
                        q.append((ny, nx))
        return total

    for i in range(h):
        for j in range(w):
            if not visited[i][j] and maps[i][j] != 'X':
                answer.append(bfs(i, j))

    if not answer:
        return [-1]
    return sorted(answer)