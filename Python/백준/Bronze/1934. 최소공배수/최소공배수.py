import sys
from math import gcd

def main():
    input = sys.stdin.readline
    t = int(input().strip())
    out = []
    for _ in range(t):
        a, b = map(int, input().split())
        g = gcd(a, b)
        out.append(str(a // g * b))
    print("\n".join(out))

if __name__ == "__main__":
    main()
