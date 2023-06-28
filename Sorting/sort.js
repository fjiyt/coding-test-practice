// 정렬 알고리즘
// sort 메소드 사용 -> 기본적으로 값을 비교할때 숫자가 아닌 문자 순서로 비교. 배열만 사용가능한 메소드여서 객체를 대상으로 정렬시 배열로 변환 후 사용해야함

// 문자 순서로 정렬되므로 [1,14,2,22,3]이 됨
const array = [2,3,1,14,22];

// 문자로 정렬
array.sort();
console.log(array);

// 문자 내림차수 정렬
array.sort();
array.reverse();
console.log(array);

//오름차순, 숫자로 정렬
array.sort((a,b)=>(a-b));
console.log(array);

//내림차순, 숫자로 정렬
array.sort((a,b)=>(b-a));
console.log(array);

// 객체 정렬시 배열 형태로 변환하면서 호출해야함
const obj = {x:5, y:2, z:3};
let temp = Object.entries(obj).sort(([,a],[,b])=>(a-b));
let temp2 = Object.entries(obj).sort(); // 앞에 문자 기준 오름차순
console.log(temp);
console.log(Object.fromEntries(temp));
console.log(temp2);