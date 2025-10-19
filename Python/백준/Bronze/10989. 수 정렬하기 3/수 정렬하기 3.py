import sys
input = sys.stdin.readline
count = [0] * 10001

N = int(input())
for _ in range(N):
    count[int(input())] += 1

for i in range(10001):
    if count[i] > 0:
        for _ in range(count[i]):
            sys.stdout.write(f"{i}\n")