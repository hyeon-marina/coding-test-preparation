import sys
input = sys.stdin.readline

def main():
    n = int(input().strip())
    arr = list(map(int, input().split()))
    sorted_unique = sorted(set(arr))
    # 값 -> 압축 인덱스 맵핑
    comp = {v:i for i,v in enumerate(sorted_unique)}
    # 각 원소에 대해 매핑된 값 출력
    result = [ str(comp[v]) for v in arr ]
    print(" ".join(result))

if __name__ == "__main__":
    main()