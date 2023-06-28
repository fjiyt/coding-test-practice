// 다익스트라 알고리즘 : 그래프에서 노드와 노드사이의 최단 경로를 구할때 사용하는 알고리즘 -> 여러개의 최단거리를 이용해 최단거리를 만든다 -> 다이나믹 프로그래밍

const graph = {
    1: {2:2, 3:5, 4:1},
    2: {3:3, 4:2},
    3: {4:3, 6:5},
    4: {3:3, 5:1},
    5: {3:1, 6:2},
    6: {},
};

const visited = Array.from({length:7}, () => false);
const distances = Array.from({length:7}, () => Number.MAX_VALUE);

function findShortestNode(distances, visited)
{
    let min = Number.MAX_VALUE;
    let index = -1;

    for(let i=1; i<distances.length; i++)
    {
        if(min > distances[i] && !visited[i])
        {
            min = distances[i];
            index = i;
        }
    }

    return index;
}
function dijkstra(start)
{
    distances[start] = 0;
    visited[start] = true;

    Object.keys(graph[start]).forEach((v) => (distances[v] = graph[start][v]));
    
    for(let i=2; i<=6; i++)
    {
        const now = findShortestNode(distances, visited);
        visited[now] = true;

        Object.keys(graph[now]).forEach((v) => {
            // now를 거쳐서 최소거리가 갱신되는지 확인
            if(distances[v] > distances[now]+graph[now][v]){
                distances[v] = distances[now] + graph[now][v];
            }
        });
    }
}

dijkstra(1);
console.log(distances);