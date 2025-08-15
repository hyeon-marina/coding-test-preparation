import math

T = int(input())
for _ in range(T):
    x, y = map(int, input().split())
    d = y - x
    n = int(math.sqrt(d))
    if n * n == d:
        print(2*n-1)
    elif n * n < d <= n * (n+1):
        print(2*n)
    else:
        print(2*n+1)
