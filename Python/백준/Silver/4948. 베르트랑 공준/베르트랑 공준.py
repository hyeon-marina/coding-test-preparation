import sys

def sieve_prefix(limit: int):
    is_prime = [True] * (limit + 1)
    if limit >= 0: is_prime[0] = False
    if limit >= 1: is_prime[1] = False

    p = 2
    while p * p <= limit:
        if is_prime[p]:
            step = p
            start = p * p
            for x in range(start, limit + 1, step):
                is_prime[x] = False
        p += 1

    prefix = [0] * (limit + 1)
    cnt = 0
    for i in range(limit + 1):
        if is_prime[i]:
            cnt += 1
        prefix[i] = cnt
    return prefix

def main():
    data = sys.stdin.read().strip().split()
    if not data:
        return
    nums = [int(x) for x in data]
    queries = [n for n in nums if n != 0]
    if not queries:
        return

    max_n = max(queries)
    limit = 2 * max_n
    prefix = sieve_prefix(limit)

    out = []
    for n in queries:
        out.append(str(prefix[2 * n] - prefix[n]))
    sys.stdout.write("\n".join(out))

if __name__ == "__main__":
    main()
