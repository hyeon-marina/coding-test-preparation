N, B = map(int, input().split())
digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"
answer = ''
while N:
    answer = digits[N % B] + answer
    N //= B
print(answer)
