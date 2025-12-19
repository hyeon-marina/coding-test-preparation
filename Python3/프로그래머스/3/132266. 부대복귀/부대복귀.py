from collections import deque

def solution(n, roads, sources, destination):
    adj = [[] for _ in range(n + 1)]
    for a, b in roads:
        adj[a].append(b)
        adj[b].append(a)

    dist = [-1] * (n + 1)
    q = deque([destination])
    dist[destination] = 0

    while q:
        cur = q.popleft()
        for nxt in adj[cur]:
            if dist[nxt] == -1:
                dist[nxt] = dist[cur] + 1
                q.append(nxt)

    return [dist[s] for s in sources]
