import sys

def main():
    input = sys.stdin.readline
    n, m = map(int, input().split())

    heard = set()
    for _ in range(n):
        heard.add(input().strip())

    ans = []
    for _ in range(m):
        name = input().strip()
        if name in heard:
            ans.append(name)

    ans.sort()
    print(len(ans))
    print("\n".join(ans))

if __name__ == "__main__":
    main()
