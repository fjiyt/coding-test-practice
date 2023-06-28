const array = [
    [1, 1, 1, 1, 1],
    [2, 2, 2, 2, 2],
    [3, 3, 3, 3, 3],
    [4, 4, 4, 4, 4],
    [5, 5, 5, 5, 5],
];

// 시계 방향 회전
function transpose(matrix) {
    return matrix.reduce((result, col) => {
        return col.map((_, i) => {
          return [col[i], ...(result[i] || [])];
        });
      }, []);
}
// 반시계 방향 회전
function transposeReverse(matrix) {
    return matrix.reduce((result, col) => {
      return col.map((_, i) => {
        return [...(result[i] || []), col[i]];
      });
    }, []);
}
  
log(transpose(array));
log(transposeReverse(array));