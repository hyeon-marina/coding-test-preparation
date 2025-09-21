import sys

def main():
    data = sys.stdin.readline().strip()
    n = int(data)
    # n^3 계산
    result = n * n * n
    print(result)
    # 최고차항의 차수
    print(3)

if __name__ == "__main__":
    main()