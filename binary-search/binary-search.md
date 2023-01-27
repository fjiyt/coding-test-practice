# 이진 탐색



## 범위를 반씩 좁혀가는 탐색



### 1. 순차탐색



리스트 안에 있는 특정한 데이터를 찾기 위해 앞에서부터 데이터를 하나씩 차례대로 확인하는 방법



```c++
#include <bits/stdc++.h>

using namespace std;

// 순차 탐색 소스코드 구현
int sequantialSearch(int n, string target, vector<string> arr) {
    // 각 원소를 하나씩 확인하며
    for (int i = 0; i < n; i++) {
        // 현재의 원소가 찾고자 하는 원소와 동일한 경우
        if (arr[i] == target) {
            return i + 1; // 현재의 위치 반환 (인덱스는 0부터 시작하므로 1 더하기)
        }
    }
    return -1; // 원소를 찾지 못한 경우 -1 반환
}

int n; // 원소의 개수
string target; // 찾고자 하는 문자열
vector<string> arr;

int main(void) {
    cout << "생성할 원소 개수를 입력한 다음 한 칸 띄고 찾을 문자열을 입력하세요." << '\n';
    cin >> n >> target;
    
    cout << "앞서 적은 원소 개수만큼 문자열을 입력하세요. 구분은 띄어쓰기 한 칸으로 합니다." << '\n';
    for (int i = 0; i < n; i++) {
        string x;
        cin >> x;
        arr.push_back(x);
    }

    // 순차 탐색 수행 결과 출력
    cout << sequantialSearch(n, target, arr) << '\n';
}

```



순차탐색은 데이터 정렬 여부와 상관없이 가장 앞에 있는 원소부터 하나씩 확인해야 한다는 점이 특징이다.

따라서 데이터의 개수가 N개일 때 최대 N번의 비교 연산이 필요하므로 순차탐색의 최악의 경우 시간 복잡도는 *O(N)* 이다.







### 2. 이진탐색



이진탐색(Binary Search)은 배열 내부의 데이터가 **정렬**되어 있어야만 사용할 수 있는 알고리즘



- 데이터가 무작위일 때는 사용할 수 없지만, 이미 정렬되어 있다면 매우 빠르게 데이터를 찾을 수 있다는 특징이 있다.

- 탐색 범위를 절반씩 좁혀가며 데이터를 탐색하는 특징이 있다.
- 위치를 나타내는 변수 3개 : 시작점, 끝점, 중간점



찾으려는 데이터와 중간점 위치에 있는 데이터를 반복적으로 비교해서 원하는 데이터를 찾는다


이진탐색은 한 번 확인할 때마다 확인하는 원소의 개수가 절반씩 줄어든다는 점에서 시간복잡도가 **O(logN)** 이다.


절반씩 데이터를 줄어들도록 만든다는 점은 다른 퀵정렬과 공통점이 있다.



#### 재귀함수 이용

```c++
#include <bits/stdc++.h>

using namespace std;

// 이진 탐색 소스코드 구현(재귀 함수)
int binarySearch(vector<int>& arr, int target, int start, int end) {
    if (start > end) return -1;
    int mid = (start + end) / 2;
    // 찾은 경우 중간점 인덱스 반환
    if (arr[mid] == target) return mid;
    // 중간점의 값보다 찾고자 하는 값이 작은 경우 왼쪽 확인
    else if (arr[mid] > target) return binarySearch(arr, target, start, mid - 1);
    // 중간점의 값보다 찾고자 하는 값이 큰 경우 오른쪽 확인
    else return binarySearch(arr, target, mid + 1, end);
}

int n, target;
vector<int> arr;

int main(void) {
    // n(원소의 개수)와 target(찾고자 하는 값)을 입력받기 
    cin >> n >> target;
    // 전체 원소 입력받기 
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        arr.push_back(x);
    }
    // 이진 탐색 수행 결과 출력 
    int result = binarySearch(arr, target, 0, n - 1);
    if (result == -1) {
        cout << "원소가 존재하지 않습니다." << '\n';
    }
    else {
        cout << result + 1 << '\n';
    }
}
```







#### 반복문 이용

```c++
#include <bits/stdc++.h>

using namespace std;

// 이진 탐색 소스코드 구현(반복문)
int binarySearch(vector<int>& arr, int target, int start, int end) {
    while (start <= end) {
        int mid = (start + end) / 2;
        // 찾은 경우 중간점 인덱스 반환
        if (arr[mid] == target) return mid;
        // 중간점의 값보다 찾고자 하는 값이 작은 경우 왼쪽 확인
        else if (arr[mid] > target) end = mid - 1;
        // 중간점의 값보다 찾고자 하는 값이 큰 경우 오른쪽 확인
        else start = mid + 1; 
    }
    return -1;
}

int n, target;
vector<int> arr;

int main(void) {
    // n(원소의 개수)와 target(찾고자 하는 값)을 입력 받기 
    cin >> n >> target;
    // 전체 원소 입력 받기 
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        arr.push_back(x);
    }
    // 이진 탐색 수행 결과 출력 
    int result = binarySearch(arr, target, 0, n - 1);
    if (result == -1) {
        cout << "원소가 존재하지 않습니다." << '\n';
    }
    else {
        cout << result + 1 << '\n';
    }
}
```






## 코딩 테스트에서의 이진탐색



이진탐색 코드는 가급적이면 외우는 걸 권장한다.



이진탐색의 원리는 다른 알고리즘에서도 폭넓게 적용되는 원리와 유사하기 때문에 매우 중요하다.

또, 높은 난이도의 문제에서는 이진 탐색 알고리즘이 다른 알고리즘과 함께 사용되기도 한다.



더불어 코딩테스트의 이진탐색문제는 탐색 범위가 큰 상황에서의 탐색을 가정하는 문제가 많다.

따라서 **2000만**을 넘어가면 이진 탐색으로 문제에 접근해보길 권한다.

처리해야 할 데이터의 개수나 값이 **1000만 단위 이상** 으로 넘어가면 이진탐색과 같이 **O(logN)** 의 속도를 내야하는 알고리즘을 떠올려야 문제가 풀린다!!





### 트리 자료구조



이진 탐색은 전제 조건이 데이터 정렬이다.

데이터베이스는 내부적으로 대용량 데이터 처리에 적합한 트리 자료구조를 이용하여 항상 데이터가 정렬되어 있다.

따라서 데이터베이스에서의 탐색은 이진 탐색과는 조금 다르지만, 이진 탐색과 유사한 방법을 이용해 항상 빠르게 수행하도록 설계되어 있어서 데이터가 많아도 탐색하는 속도가 빠르다.



#### 특징

- 트리는 부모노드와 자식노드의 관계로 표현한다.
- 트리의 최상단 노드를 루트 노드라고 한다.
- 트리의 최하단 노드를 단말 노드라고 한다.
- 트리에서 일부를 떼어내도 트리 구조이며 이를 서브 트리라 한다.
- 트리는 파일 시스템과 같이 계층적이고 정렬된 데이터를 다루기에 적합하다.



큰 데이터를 처리하는 소프트웨어는 대부분 데이터를 트리 자료구조로 저장해서 이진 탐색과 같은 탐색 기법을 이용해 빠르게 탐색이 가능하다.

그렇다면 이런 트리 구조를 이용하면 정확히 어떤 방식으로 항상 이진 탐색이 가능할 걸까?







### 이진 탐색 트리



이진탐색이 동작할 수 있도록 고안된, 효율적인 탐색이 가능한 자료구조이다.



#### 특징

- 부모 노드보다 왼쪽 자식 노드가 작다.

- 부모 노드보다 오른쪽 자식 노드가 크다.

  

**왼쪽 자식 노드 < 부모 노드 < 오른쪽 자식 노드**











