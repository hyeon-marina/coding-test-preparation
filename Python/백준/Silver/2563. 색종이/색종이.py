N = int(input())
paper = [[0] * 100 for _ in range(100)]

for _ in range(N):
    x, y = map(int, input().split())
    for i in range(x, x + 10):
        for j in range(y, y + 10):
            paper[i][j] = 1  # 칸에 색종이가 붙었음을 표시

total = 0
for i in range(100):
    total += sum(paper[i])
print(total)
