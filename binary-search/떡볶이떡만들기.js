// [문제] 떡볶이 떡 만들기
// 손님이 떡볶이를 만들기 위해 떡을 사러 왔다.
// 떡은 너무 길기 때문에 절단기를 통해 손님이 원하는 만큼 잘라줘야 한다.
// 절단기로 떡을 자를 때는 모든 떡이 일괄로 잘리게 된다.
// 떡이 17cm, 19cm, 14cm 세 개가 있고, 절단기의 높이가 15cm라면 잘랐을 때 총 6cm가 나온다.
// 손님이 원하는 길이로 잘라주려면 절단기의 높이를 몇으로 해야 하는가?

const need = 6;
const dducks = [19,15,10,17];

function binarySearch(arr, target, start, end) {
    if(start > end) return null;

    const mid = Math.floor((start+end)/2);
    // let sum = 0;
    // for(let i=0; i<arr.length; i++)
    // {
    //     let temp = arr[i] - mid;
    //     if(temp < 0) continue;
    //     sum += temp;
    // }

    const sum = arr.reduce((pre, cur) => {
        let temp = cur - mid;
        return temp <= 0 ? pre : pre+temp;
    },0);

    if(sum===target) return mid;
    else if(sum < target) return binarySearch(arr, target, start, mid-1);
    else if (sum > target) return binarySearch(arr, target, mid+1, end);
}

console.log(binarySearch(dducks, need, 0, Math.max(...dducks)));