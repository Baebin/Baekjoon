import sys

if __name__ == "__main__":
    alphabets = [0] * 26

    str = sys.stdin.readline().rstrip()
    for c in str:
        alphabets[ord(c) - ord('a')] += 1
    for i in range(26):
        print(alphabets[i], end=" ")