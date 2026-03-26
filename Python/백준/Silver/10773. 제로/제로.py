import sys

# 입력 속도 최적화
input = sys.stdin.read
data = input().split()

K = int(data[0])
stack = []

for i in range(1, K + 1):
    num = int(data[i])
    if num == 0:
        stack.pop()  # 최근 숫자 제거
    else:
        stack.append(num)  # 숫자 추가

print(sum(stack))