from collections import deque
import sys
input = sys.stdin.readline

T = int(input())
for _ in range(T):
    N, K = map(int, input().split())
    D = list(map(int, input().split()))
    adj = [[] for _ in range(N)]
    indegree = [0]*N
    for _ in range(K):
        X, Y = map(int, input().split())
        adj[X-1].append(Y-1)
        indegree[Y-1] += 1
    W = int(input()) - 1
    dp = D[:]
    q = deque([i for i in range(N) if indegree[i]==0])
    while q:
        now = q.popleft()
        for nxt in adj[now]:
            dp[nxt] = max(dp[nxt], dp[now]+D[nxt])
            indegree[nxt] -= 1
            if indegree[nxt] == 0:
                q.append(nxt)
    print(dp[W])
