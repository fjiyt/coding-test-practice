import sys

myinput = sys.stdin.read()
s = myinput.replace('\n', '').replace(' ', '')

li = [0] * 26

for c in s:
    li[ord(c) - 97] += 1

for i in range(26):
    if li[i] == max(li):
        print(chr(97 + i), end='')
