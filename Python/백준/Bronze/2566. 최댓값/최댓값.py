nums = []
for i in range(9):
    num = list(map(int, input().split()))
    nums.append(num)

max_num = nums[0][0]
max_i, max_j = 0, 0

for i in range(9):
    for j in range(9):
        if nums[i][j] > max_num:
            max_num = nums[i][j]
            max_i, max_j = i, j

print(max_num)
print(max_i + 1, max_j + 1)
