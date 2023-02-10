import sys

n, x = map(int, sys.stdin.readline().split())
A = list(map(int, sys.stdin.readline().split()))
for a in A:
	if (a < x):
		print(a, end = " ")