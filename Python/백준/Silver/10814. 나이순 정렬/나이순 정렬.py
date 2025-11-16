import sys
input = sys.stdin.readline

def main():
    N = int(input().rstrip())
    arr = []
    for _ in range(N):
        line = input().split()
        age = int(line[0])
        name = line[1]
        arr.append((age, name))
    # 파이썬의 sort는 안정 정렬이므로, 나이만 key로 지정하면
    # 같은 나이인 경우 입력 순서가 유지됨
    arr.sort(key=lambda x: x[0])
    out = []
    for age, name in arr:
        out.append(f"{age} {name}")
    sys.stdout.write("\n".join(out))

if __name__ == "__main__":
    main()