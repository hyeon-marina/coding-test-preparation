x_coords = []
y_coords = []

for _ in range(3):
    x, y = map(int, input().split())
    x_coords.append(x)
    y_coords.append(y)

# count를 이용해 한 번만 나오는 좌표 선택
for xi in x_coords:
    if x_coords.count(xi) == 1:
        x_ans = xi
        break

for yi in y_coords:
    if y_coords.count(yi) == 1:
        y_ans = yi
        break

print(x_ans, y_ans)