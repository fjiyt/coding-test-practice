# [Easy] Implement Queue using Stacks
📍[문제링크](https://leetcode.com/problems/implement-queue-using-stacks/description/)\
📍[제출결과](https://leetcode.com/problems/implement-queue-using-stacks/submissions/1028677355/)

## Key point
### 스택을 이용해서 큐를 구현하는 방법 -> *스택 2개 사용*
- push
  - push 전용 스택에 넣는다.
- pop
  - pop 전용 스택에서 pop 한다.
  - 만약 pop 전용 스택이 비었다면, push 스택에서 모든 값을 pop 스택으로 옮긴 후 pop
- peek
  - pop 전용 스택에서 peek 한다.
  - 만약 pop 전용 스택이 비었다면, push 스택에서 모든 값을 pop 스택으로 옮긴 후 peek
- empty
  - pop 스택과 push 스택이 모두 비었으면, true
 
### 큐를 이용해서 스택을 구현하는 방법 -> *큐 1개 사용*
- push
  - 스택에 push 한다.
- pop
  - 마지막 데이터가 나올때까지 stack에서 데이터를 pop하고 다시 push한다.
  - 마지막 데이터를 기억해놓아야 한다.
- peek
  - 마지막 데이터가 나올때까지 stack에서 데이터를 pop하고 다시 push한다.
  - 마지막 데이터를 기억해놓아야 한다.
- empty
  - 스택이 모두 비었으면, true
