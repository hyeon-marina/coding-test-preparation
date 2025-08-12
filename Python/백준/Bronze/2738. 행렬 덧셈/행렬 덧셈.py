A, B = map(int, input().split())

matrix1, matrix2 = [],[]

for i in range(A):
    row = list(map(int, input().split()))
    matrix1.append(row)

for j in range(A):
    row = list(map(int, input().split()))
    matrix2.append(row)

for row in range(A):
    for col in range(B):
        print(matrix1[row][col] + matrix2[row][col], end=' ')
    print()
