# [Easy] Linked List Cycle
📍[문제링크](https://leetcode.com/problems/linked-list-cycle/description/)\
📍[제출결과](https://leetcode.com/problems/linked-list-cycle/submissions/1028667969/)

## Key point
### Floyd's slow and fast 이론 사용
- Cycle을 가지면 slow, fast 포인터가 결국에 만나게 된다는 이론
- slow pointer : 한단계씩 움직임
- fast pointer : 두단계씩 움직임 (더 빠르게 나가도 됨)
- 만약 사이클이 없다면, 빠른 포인터는 연결 리스트의 끝에 도달하여 null을 가리키게 됨.
- 하지만 사이클이 있다면, 빠른 포인터와 느린 포인터는 언젠가 만나게 되어 사이클의 존재를 확인할 수 있음
