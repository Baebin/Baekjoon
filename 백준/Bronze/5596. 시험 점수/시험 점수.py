import sys

if __name__ == "__main__":
    ans = 0

    for i in range(2):
        subjects = list(map(int, sys.stdin.readline().rstrip().split()))
        ans = max(ans, sum(subjects))
    print(ans)