import sys

if __name__ == "__main__":
    arr = ['i', 'I', 'a', 'A', 'e', 'E', 'o', 'O', 'u', 'U'];

    while True:
        str = sys.stdin.readline().rstrip()
        if str == '#':
            break
        cnt = 0
        for c in str:
            if c in arr:
                cnt += 1
        print(cnt)