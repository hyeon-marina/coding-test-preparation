import sys
input = sys.stdin.readline

def main():
    N, k = map(int, input().split())
    scores = list(map(int, input().split()))
    # 내림차순 정렬
    scores.sort(reverse=True)
    # k번째 사람이 받는 점수 → 인덱스 k-1
    print(scores[k-1])

if __name__ == "__main__":
    main()