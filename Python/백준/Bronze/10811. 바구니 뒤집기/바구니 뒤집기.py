N, M = map(int, input().split())
basket = [i for i in range(1, N+1)]

for _ in range(M):
    i, j = map(int, input().split())
    # 슬라이싱 역순 대입
    basket[i-1:j] = basket[i-1:j][::-1]

print(' '.join(map(str, basket)))
