import sys

if __name__ == "__main__":
    ans = sum(int(sys.stdin.readline().rstrip()) for _ in range(5))
    print(ans)