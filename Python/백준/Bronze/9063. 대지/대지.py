n = int(input())
if n == 1:
    print(0)
else:
    xs = []
    ys = []
    for _ in range(n):
        x, y = map(int, input().split())
        xs.append(x)
        ys.append(y)
    print((max(xs) - min(xs)) * (max(ys) - min(ys)))