import sys
from math import gcd

def main():
    a, b = map(int, sys.stdin.readline().split())
    g = gcd(a, b)
    print(a // g * b)

if __name__ == "__main__":
    main()
