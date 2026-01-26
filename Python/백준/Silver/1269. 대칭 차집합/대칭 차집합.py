import sys

def main():
    input = sys.stdin.readline
    n, m = map(int, input().split())
    A = set(map(int, input().split()))
    B = set(map(int, input().split()))
    print(len(A) + len(B) - 2 * len(A & B))

if __name__ == "__main__":
    main()
