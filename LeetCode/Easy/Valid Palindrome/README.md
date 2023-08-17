# [Easy] Valid Palindrome
📍[문제링크](https://leetcode.com/problems/valid-palindrome/)\
📍[제출결과](https://leetcode.com/problems/valid-palindrome/submissions/1024026087/)

## Needs
- 문자를 알파벳/숫자/기호로 구분할 수 있는가
  - 첫번째 방법
    ```java
    if(c-'0' >=0 && c-'0'<=9)
             
    if(c-'A' >= 0 && c-'A' <=25)
             
    if(c-'a' >= 0 && c-'a' <=25)
    ```
  - 두번째 방법
    ```java
    Character.isLetterOrDigit(c);
    ```
- 아스키코드로 변환할 수 있는가
  ```java
  if(c-'0' >=0 && c-'0'<=9)
             
  if(c-'A' >= 0 && c-'A' <=25)
             
  if(c-'a' >= 0 && c-'a' <=25)
  ```

  - 0-9 : 80-89
  - A-Z : 65-90 (26개)
  - a-z : 97-122 (26개)
  - 대문자 + 32 = 소문자
- 문자(열)은 소문자로 변환할 수 있는가
  ```java
  // 문자 소문자 변환
  Character.toLowerCase(c);

  // 문자열 소문자 변환
  str.toLowerCase();
  ```
## 모범답안
```java
class Solution {
    public boolean isPalindrome(String s) {

        if(s.length()<=1) return true;

        int start = 0;
        int last = s.length()-1;

        while(start < last)
        {
            char c_start = s.charAt(start);
            char c_last = s.charAt(last);

            if(!Character.isLetterOrDigit(c_start))
            {
                start++;
            }
            else if(!Character.isLetterOrDigit(c_last))
            {
                last--;
            }
            else if(Character.toLowerCase(c_start) == Character.toLowerCase(c_last)) {
                start++; last--;
            }
            else return false;
        }

        return true;
    }
}
```
