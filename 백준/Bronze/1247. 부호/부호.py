import sys

if __name__ == "__main__":
    for i in range(3):
        N = int(sys.stdin.readline())
        ans = sum(int(sys.stdin.readline()) for _ in range(N))
        if ans == 0:
            print(0)
        else:
            print('+' if (ans > 0) else '-')