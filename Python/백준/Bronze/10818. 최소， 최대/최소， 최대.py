N = int(input())
numbers = list(map(int, input().split()))
min_num = max_num = numbers[0]
for num in numbers[1:]:
    if num < min_num:
        min_num = num
    elif num > max_num:
        max_num = num
print(min_num, max_num)
