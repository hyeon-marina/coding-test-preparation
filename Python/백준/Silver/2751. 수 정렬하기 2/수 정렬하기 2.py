import sys
input = sys.stdin.readline
def main():
    N = int(input().strip())
    arr = []
    for _ in range(N):
        arr.append(int(input().strip()))
    # 정렬 (O(N log N))
    arr.sort()
    # 출력 — join + write 방식이 빠르다
    sb = []
    for x in arr:
        sb.append(str(x))
    sys.stdout.write("\n".join(sb))

if __name__ == "__main__":
    main()