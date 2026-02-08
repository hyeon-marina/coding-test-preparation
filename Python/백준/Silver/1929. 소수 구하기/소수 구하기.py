import sys

def main():
    input = sys.stdin.readline
    m, n = map(int, input().split())

    is_prime = bytearray(b"\x01") * (n + 1)
    if n >= 0: is_prime[0] = 0
    if n >= 1: is_prime[1] = 0

    limit = int(n ** 0.5)
    for i in range(2, limit + 1):
        if is_prime[i]:
            start = i * i
            step = i
            is_prime[start:n + 1:step] = b"\x00" * (((n - start) // step) + 1)

    out = []
    for x in range(max(2, m), n + 1):
        if is_prime[x]:
            out.append(str(x))
    sys.stdout.write("\n".join(out))

if __name__ == "__main__":
    main()
