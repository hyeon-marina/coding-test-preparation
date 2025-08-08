dial = ['ABC', 'DEF', 'GHI', 'JKL', 'MNO', 'PQRS', 'TUV', 'WXYZ']
word = input()
result = 0
for char in word:
    for group in dial:
        if char in group:
            result += dial.index(group) + 3  # 다이얼 번호에 1초 더하는 방식 대신 +3 사용 (2초부터 시작)
print(result)
