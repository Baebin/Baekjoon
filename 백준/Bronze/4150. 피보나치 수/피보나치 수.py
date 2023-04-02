import sys

if __name__ == "__main__":
    N = int(sys.stdin.readline())
    fibo = [0, 1, 1]
    for i in range(3, N):
        fibo.append(fibo[i - 1] + fibo[i - 2])
    print(fibo[N - 1] + fibo[N - 2])