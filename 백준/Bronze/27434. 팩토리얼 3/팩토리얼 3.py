import sys

if __name__ == "__main__":
    N = int(sys.stdin.readline())
    fac = 1
    for i in range(N):
        fac *= (i + 1);
    print(fac)