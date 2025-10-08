import sys
input = sys.stdin.readline

def solve():
    n = int(input().strip())
    # 최대한 많은 5kg 봉지를 쓰고, 남은 무게를 3kg으로 맞추는 방식
    count5 = n // 5
    while count5 >= 0:
        rem = n - count5 * 5
        if rem % 3 == 0:
            count3 = rem // 3
            print(count5 + count3)
            return
        count5 -= 1
    # 반복을 다 해도 못 맞추면
    print(-1)

if __name__ == "__main__":
    solve()