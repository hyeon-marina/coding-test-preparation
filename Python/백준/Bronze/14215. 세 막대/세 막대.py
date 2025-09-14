import sys
input = sys.stdin.readline

def main():
    a, b, c = map(int, input().split())
    sticks = sorted([a, b, c])
    x, y, z = sticks  # z는 가장 긴 변

    if x + y > z:
        print(x + y + z)
    else:
        # z를 x + y - 1로 줄임
        print(2 * (x + y) - 1)

if __name__ == "__main__":
    main()