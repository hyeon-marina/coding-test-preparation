import sys
input = sys.stdin.readline

def main():
    n = int(input().strip())
    arr = []
    for _ in range(n):
        arr.append(int(input().strip()))
    arr.sort()
    # 출력
    out = '\n'.join(str(x) for x in arr)
    print(out)

if __name__ == "__main__":
    main()