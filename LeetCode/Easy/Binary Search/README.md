# [Easy] Binary Search
📍[문제링크](https://leetcode.com/problems/binary-search/)\
📍[제출결과](https://leetcode.com/problems/binary-search/submissions/1024873590/)

## Key point
- 문제조건 : O(log n), 정렬된 숫자 -> **Binary Search**

### Array.binarySearch 사용
```java
class Solution {
    public int search(int[] nums, int target) {
        int idx = Arrays.binarySearch(nums, target);

        if(idx < 0) return -1;
        return idx;
    }
}
```

### 직접구현
```java
class Solution {
    public int search(int[] nums, int target) {
        int left = 0;
        int right = nums.length-1;

        while(left <= right)
        {
            int mid = (left+right) / 2;
            if(nums[mid] < target)
            {
                left = mid+1;
            }
            else if(nums[mid] > target)
            {
                right = mid - 1;
            }
            else{
                return mid;
            }
        }

        return -1;
    }
}
```
