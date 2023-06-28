// 이미 정렬된 데이터 집합을 대상으로 사용할 수 있다.
function binarySearch(arr, target, start, end) {
    if(start > end) return null;

    const mid = Math.floor((start+end)/2);

    // 가운데 값을 비교 후 분기에 따라 처리
    if(target === arr[mid]) return mid;
    else if(target < arr[mid]) return binarySearch(arr, target, start, mid-1);
    else if(target > arr[mid]) return binarySearch(arr, target, mid+1, end);
}

const array = [1,2,3,4,5,6,7,8,9];
console.log(binarySearch(array,2,0,array.length-1));