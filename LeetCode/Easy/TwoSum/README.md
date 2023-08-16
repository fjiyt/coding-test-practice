# [Easy] Two Sum
📍[문제링크](https://leetcode.com/problems/two-sum/description/)\
📍[제출결과](https://leetcode.com/problems/two-sum/submissions/1023017062/)

## Key point
O(n^2)이 되지 않도록 하는 방법
- HashMap을 이용해 (값, 인덱스) 저장

## 과정

- target과 number의 차이인 remain 값이 HashMap에 존재하는지 확인
  - 존재하면, 해당 인덱스와 현재 인덱스를 리턴
  - 존재하지 않으면, HashMap에 (number, index) 저장
