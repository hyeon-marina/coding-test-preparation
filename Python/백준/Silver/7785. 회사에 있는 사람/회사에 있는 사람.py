import sys

input = sys.stdin.readline

n = int(input())
present = set()

for _ in range(n):
    name, action = input().split()
    if action == "enter":
        present.add(name)
    else:  # leave
        present.discard(name)

for name in sorted(present, reverse=True):
    print(name)
