import sys

loop = int(sys.stdin.readline())

for i in range(loop):
	a, b = map(int, sys.stdin.readline().split())
	print(a + b)
