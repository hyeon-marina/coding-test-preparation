import sys
from math import gcd

def main():
    input = sys.stdin.readline
    a, b = map(int, input().split())
    c, d = map(int, input().split())

    num = a * d + c * b
    den = b * d

    g = gcd(num, den)
    print(num // g, den // g)

if __name__ == "__main__":
    main()
