# heap
## 개념
heap은 **이진 트리 자료구조** 이다.
부모와 자식과의 관계에 따라 Min Heap / Max Heap으로 나눌 수 있다.

Min Heap : 부모 <= 자식 
-> 루트 노드 : min 값 

Max Heap : 부모 >= 자식
-> 루트 노드 : max 값

원소의 추가/제거 과정 : O(logN)

조회 : O(1)

## priority queue
위에서 본 Heap 자료구조를 응용한 대표적인 사례가 priority queue(우선순위 큐)이다. 이는 우선순위를 순차적으로 가져올 수 있는 push/pop이 가능한 자료로 꼭 heap으로 구현될 필요는 없지만, heap으로 구현하는 것이 시간복잡도 면에서 큰 효율을 낼 수 있다.

Max Heap : priority_queue<int> pq;
default가 맥스 힙

Min Heap :
priority_queue <int, vector<int>, greater<int>> pq;
원소에 전체적으로 음수 취해주기
인자 넣기

### pair 사용
pair를 사용해서 우선순위 큐를 사용할 수도 있다. 따라서 pair의 첫번째 요소로 먼저 비교하고, 같은 경우 두번째 요소로 비교하는 방식이다.