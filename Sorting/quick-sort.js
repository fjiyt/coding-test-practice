function quickSort(arr) {

    if(arr.length <= 1) return arr;

    const pivot = arr[0];

    const left = arr.filter(element => (element < pivot));
    const right = arr.filter(element => (element > pivot));

    return quickSort(left).concat([pivot], quickSort(right));
}

const array = [2,5,4,3,1,7,6];
console.log(quickSort(array));