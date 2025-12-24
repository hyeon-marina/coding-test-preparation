import sys

def main():
    input = sys.stdin.readline
    n, m = map(int, input().split())

    S = set()
    for _ in range(n):
        S.add(input().strip())

    ans = 0
    for _ in range(m):
        if input().strip() in S:
            ans += 1

    print(ans)

if __name__ == "__main__":
    main()
