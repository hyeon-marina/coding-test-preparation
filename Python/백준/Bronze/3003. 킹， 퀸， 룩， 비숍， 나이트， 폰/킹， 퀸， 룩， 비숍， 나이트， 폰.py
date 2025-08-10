pieces = [1, 1, 2, 2, 2, 8]
current = list(map(int, input().split()))
print(*(pieces[i] - current[i] for i in range(6)))