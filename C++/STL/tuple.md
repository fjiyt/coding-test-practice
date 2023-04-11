# Tuple

사물의 유한한 순서를 뜻함
두개 이상의 순서대로 정렬된 서로 다른 값을 저장할때 사용함

```c++
std::tuple<int,char,string> Value(10,x,"string")
```

<> 안에 데이터 형을 나열

## tuple 활용시 사용하는 함수들
- make_tuple : 튜플을 만드는 함수
- get : 튜플로부터 값을 가져오는 함수
- swap : 다른 튜플과 값을 바꾸는 함수
- = : 튜플의 값을 다른 변수에 전달

## 함수 사용 예시
```c++
auto t = std::make_tuple(10,'x',"string");
std::get<2>(t);
std::swap(tup1, tup2);
std::tie(x,y,z) = t;
```

tie 키워드를 이용해서 tuple의 각 값을 x, y, z에 저장함