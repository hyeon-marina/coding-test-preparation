import sys
input = sys.stdin.readline

def self_sum(x: int) -> int:
    s = x
    while x > 0:
        s += x % 10
        x //= 10
    return s

def main():
    N = int(input().strip())
    ans = 0
    # 탐색 범위를 줄이기: 최대 자릿수 * 9 만큼 뒤까지만
    strN = str(N)
    d = len(strN)
    start = max(1, N - 9 * d)
    for m in range(start, N):
        if self_sum(m) == N:
            ans = m
            break
    
    print(ans)

if __name__ == "__main__":
    main()