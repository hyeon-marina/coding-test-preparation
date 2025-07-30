students = set(range(1, 31))
for _ in range(28):
    students.remove(int(input()))
for s in sorted(students):
    print(s)
