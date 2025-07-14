a, b = map(int, input().split())
c = int(input())

total_minutes = a * 60 + b + c
hour = (total_minutes // 60) % 24
minute = total_minutes % 60

print(hour, minute)
