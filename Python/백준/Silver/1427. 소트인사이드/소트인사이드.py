import sys
input = sys.stdin.readline

def main():
    n = input().strip()
    digits = list(n)
    digits.sort(reverse=True)
    print(''.join(digits))

if __name__ == "__main__":
    main()