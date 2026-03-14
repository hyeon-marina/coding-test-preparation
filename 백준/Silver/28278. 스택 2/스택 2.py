import sys

input = sys.stdin.readline

n = int(input())
stack = []
out = []

for _ in range(n):
    cmd = input().split()
    op = int(cmd[0])

    if op == 1:
        stack.append(int(cmd[1]))
    elif op == 2:
        if stack:
            out.append(str(stack.pop()))
        else:
            out.append("-1")
    elif op == 3:
        out.append(str(len(stack)))
    elif op == 4:
        out.append("0" if stack else "1")
    elif op == 5:
        if stack:
            out.append(str(stack[-1]))
        else:
            out.append("-1")

sys.stdout.write("\n".join(out))