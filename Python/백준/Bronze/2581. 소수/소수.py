import sys
import math

M = int(sys.stdin.readline())
N = int(sys.stdin.readline())

primes = []
for num in range(M, N+1):
    if num < 2:
        continue
    is_prime = True
    for i in range(2, int(math.isqrt(num)) + 1):
        if num % i == 0:
            is_prime = False
            break
    if is_prime:
        primes.append(num)

if len(primes) == 0:
    print(-1)
else:
    print(sum(primes))
    print(primes[0])
