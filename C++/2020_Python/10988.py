import sys

input = sys.stdin.readline

test = input().rstrip()
test_compare = test[::-1]

if test == test_compare:
    print(1)
else:
    print(0)
