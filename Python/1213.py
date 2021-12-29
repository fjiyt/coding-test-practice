import sys

input = sys.stdin.readline
name = input().rstrip()


def Sum(cnt):
    num = 0
    for i in cnt:
        if(i % 2 == 1):
            num += 1
        if(num >= 2):
            return False

    return True


cnt = []


if (Sum(cnt) == False):
    print("I'm Sorry Hansoo")
