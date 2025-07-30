remainders = set()
for _ in range(10):
    n = int(input())
    remainders.add(n % 42)
print(len(remainders))
