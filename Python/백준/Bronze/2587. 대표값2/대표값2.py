import sys
input = sys.stdin.readline

def main():
    nums = [int(input()) for _ in range(5)]
    nums.sort()
    total = sum(nums)
    avg = total // 5
    mid = nums[2]
    print(avg)
    print(mid)

if __name__ == "__main__":
    main()