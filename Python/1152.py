import sys

input = sys.stdin.readline

test = input().strip().split(" ")

if test[0] == "":
    print(0)
else:
    print(len(test))
