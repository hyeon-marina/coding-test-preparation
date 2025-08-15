# 입력받기
T = int(input())
for _ in range(T):
    C = int(input())
    for coin in [25, 10, 5, 1]:
        print(C // coin, end=' ')
        C %= coin
    print()
