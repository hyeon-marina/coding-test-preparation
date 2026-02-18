import sys

def sieve(n: int):
    is_prime = bytearray(b'\x01') * (n + 1)
    if n >= 0: is_prime[0] = 0
    if n >= 1: is_prime[1] = 0
    limit = int(n ** 0.5)
    for i in range(2, limit + 1):
        if is_prime[i]:
            step = i
            start = i * i
            is_prime[start:n+1:step] = b'\x00' * (((n - start) // step) + 1)
    return is_prime

def main():
    input = sys.stdin.readline
    t = int(input().strip())
    nums = [int(input().strip()) for _ in range(t)]
    max_n = max(nums) if nums else 0

    is_prime = sieve(max_n)

    out = []
    for n in nums:
        cnt = 0
        half = n // 2
        for p in range(2, half + 1):
            if is_prime[p] and is_prime[n - p]:
                cnt += 1
        out.append(str(cnt))
    sys.stdout.write("\n".join(out))

if __name__ == "__main__":
    main()
