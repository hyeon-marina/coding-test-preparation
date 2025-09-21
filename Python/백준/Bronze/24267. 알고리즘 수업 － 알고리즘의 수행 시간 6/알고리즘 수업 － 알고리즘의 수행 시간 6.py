import sys

def main():
    input_data = sys.stdin.readline().strip()
    n = int(input_data)
    # 수행횟수 계산
    # (n * (n-1) * (n-2)) // 6
    count = n * (n - 1) * (n - 2) // 6
    print(count)
    print(3)

if __name__ == "__main__":
    main()