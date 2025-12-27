import sys
input = sys.stdin.readline

n = int(input())
cards = list(map(int, input().split()))
m = int(input())
queries = list(map(int, input().split()))

cnt = {}
for x in cards:
    cnt[x] = cnt.get(x, 0) + 1

out = [str(cnt.get(q, 0)) for q in queries]
print(" ".join(out))
