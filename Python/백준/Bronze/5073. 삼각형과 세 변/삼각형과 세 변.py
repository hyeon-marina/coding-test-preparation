import sys
input = sys.stdin.readline

while True:
    a, b, c = map(int, input().split())
    if a == 0 and b == 0 and c == 0:
        break

    # 정렬: 가장 긴 변을 맨 마지막에
    sides = sorted([a, b, c])
    x, y, z = sides  # z는 가장 긴 변

    if x + y <= z:
        print("Invalid")
    else:
        if x == y == z:
            print("Equilateral")
        elif x == y or y == z or x == z:
            print("Isosceles")
        else:
            print("Scalene")