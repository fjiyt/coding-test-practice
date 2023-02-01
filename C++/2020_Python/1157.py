import sys

input = sys.stdin.readline

test = input().upper()
unique_list = list(set(test))
cnt_list = []

for i in unique_list:
    count = test.count(i)
    cnt_list.append(count)

if cnt_list.count(max(cnt_list)) >= 2:
    print("?")
else:
    print(unique_list[cnt_list.index(max(cnt_list))].upper())
