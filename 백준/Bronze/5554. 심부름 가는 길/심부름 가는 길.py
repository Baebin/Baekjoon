import sys

if __name__ == "__main__":
    total = sum(int(sys.stdin.readline().rstrip()) for _ in range(4))
    print(total // 60, total % 60, sep="\n")