import sys

def main():
    data = sys.stdin.readline().split()
    a1 = int(data[0]); a0 = int(data[1])
    c = int(sys.stdin.readline().strip())
    n0 = int(sys.stdin.readline().strip())
    if a1 <= c and (a1 * n0 + a0) <= c * n0:
        print(1)
    else:
        print(0)

if __name__ == "__main__":
    main()