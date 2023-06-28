// union-find 사용. 임의의 두 노드가 소속된 집합이 달라 서로가 서로에게 도달할 수 없음을 의미

function findParent(parent, n)
{
    if(parent[n]===n) return n;
    else {
        return findParent(parent, parent[n]);
    }
}
function union(parent, a, b)
{
    a = findParent(parent, a);
    b = findParent(parent, b);

    if(a<b) parent[b] = a;
    else parent[a] = b;
}
// 노드 개수, 부모 테이블 (초기값은 자기 자신으로 설정)
const n = 6;
const parent = Array.from({length:n+1}, (_,i)=>i);
// 간선 연결 [노드, 노드, 거리(가중치)]
const edges = [
    [1,2,29],
    [1,5,75],
    [2,3,35],
    [2,6,34],
    [3,4,7],
    [4,6,23],
    [5,6,53],
];

edges.sort((a,b) => a[2]-b[2]);

let result = 0;
let cnt = 0;
edges.forEach((edge) => {
    if(cnt===n-1) return result;
    const [a,b,cost] = edge;

    if(findParent(parent, a) !== findParent(parent,b)){
        union(parent, a,b);
        result += cost;
        cnt++;
    }
});

console.log(result);