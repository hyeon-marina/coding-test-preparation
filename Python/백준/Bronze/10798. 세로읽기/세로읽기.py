lines = [list(input().rstrip()) for _ in range(5)]
result = []

for col in range(15):      # 최대 15개의 문자
    for row in range(5):   # 5줄
        if col < len(lines[row]):  
            result.append(lines[row][col])

print(''.join(result))
