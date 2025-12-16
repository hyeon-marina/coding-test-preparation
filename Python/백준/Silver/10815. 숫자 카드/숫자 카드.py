import sys
from bisect import bisect_left

input = sys.stdin.readline

n = int(input().strip())
cards = list(map(int, input().split()))
cards.sort()

m = int(input().strip())
queries = list(map(int, input().split()))

out = []
for x in queries:
    i = bisect_left(cards, x)
    out.append('1' if i < n and cards[i] == x else '0')

sys.stdout.write(' '.join(out))
