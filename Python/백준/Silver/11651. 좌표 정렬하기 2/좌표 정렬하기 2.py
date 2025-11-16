import sys
input = sys.stdin.readline

def main():
    n = int(input())
    coords = [tuple(map(int, input().split())) for _ in range(n)]
    # 정렬 키: (y, x)
    coords.sort(key=lambda xy: (xy[1], xy[0]))
    out = []
    for x, y in coords:
        out.append(f"{x} {y}")
    sys.stdout.write("\n".join(out))

if __name__ == "__main__":
    main()