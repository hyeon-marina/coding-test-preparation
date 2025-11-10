import sys
input = sys.stdin.readline

def main():
    n = int(input())
    pts = []
    for _ in range(n):
        x, y = map(int, input().split())
        pts.append((x, y))
    pts.sort(key=lambda p: (p[0], p[1]))
    out = []
    for x, y in pts:
        out.append(f"{x} {y}")
    sys.stdout.write("\n".join(out))

if __name__ == "__main__":
    main()