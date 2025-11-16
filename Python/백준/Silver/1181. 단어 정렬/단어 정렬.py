import sys
input = sys.stdin.readline

def main():
    n = int(input())
    words = [input().rstrip('\n') for _ in range(n)]
    # 중복 제거
    words = list(set(words))
    # 길이 기준 오름차순 → 길이 동일 시 사전순
    words.sort(key=lambda w: (len(w), w))
    sys.stdout.write("\n".join(words))

if __name__ == "__main__":
    main()