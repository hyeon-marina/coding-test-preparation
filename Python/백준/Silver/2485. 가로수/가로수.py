import sys
from math import gcd

input = sys.stdin.readline

def main():
    n = int(input().strip())
    pos = [int(input().strip()) for _ in range(n)]
    pos.sort()

    diffs = [pos[i] - pos[i - 1] for i in range(1, n)]
    g = diffs[0]
    for d in diffs[1:]:
        g = gcd(g, d)

    ans = 0
    for d in diffs:
        ans += (d // g) - 1

    print(ans)

if __name__ == "__main__":
    main()
