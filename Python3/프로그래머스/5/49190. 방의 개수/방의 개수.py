def solution(arrows):
    dx = [0, 1, 1, 1, 0, -1, -1, -1]
    dy = [-1, -1, 0, 1, 1, 1, 0, -1]

    x, y = 0, 0
    visited_nodes = set()
    visited_nodes.add((x, y))
    edges = set()

    rooms = 0

    for d in arrows:
        # 한 방향 지시마다 두 번 이동
        for _ in range(2):
            nx = x + dx[d]
            ny = y + dy[d]

            # 이미 정점을 방문했었고, 간선은 처음 쓰는 경우 → 방 생성
            if (nx, ny) in visited_nodes and (x, y, nx, ny) not in edges:
                rooms += 1

            # 간선 등록 (정방향/역방향 둘 다)
            edges.add((x, y, nx, ny))
            edges.add((nx, ny, x, y))

            # 정점 등록
            visited_nodes.add((nx, ny))

            # 이동
            x, y = nx, ny

    return rooms