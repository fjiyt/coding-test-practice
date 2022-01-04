import sys

input = sys.stdin.readline

word = input().strip().upper()
word_unique = list(set(word))
word_count = []

for i in word_unique:
    word_count.append(word.count(i))

if word_count.count(max(word_count)) >= 2:
    print("?")
else:
    print(word_unique[word_count.index(max(word_count))])
