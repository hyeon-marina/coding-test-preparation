N, M = map(int, input().split())
baskets = list(range(1, N + 1))  # 각 바구니에 자신의 번호에 맞는 공을 넣음

for _ in range(M):
    i, j = map(int, input().split())
    baskets[i - 1], baskets[j - 1] = baskets[j - 1], baskets[i - 1]  # 교환

print(*baskets)
