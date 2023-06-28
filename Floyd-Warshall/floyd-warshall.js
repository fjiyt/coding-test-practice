const graph = [
    [1e9, 1e9, 1e9, 1e9, 1e9],
    [1e9, 0, 4, 1e9, 6],
    [1e9, 3, 0, 7, 1e9],
    [1e9, 5, 1e9, 0, 4],
    [1e9, 1e9, 1e9, 2, 0],
];

for(let k=1; k<=4; k++)
{
    for(let i=1; i<=4; i++)
    {
        for(let j=1; j<=4; j++)
        {
            if(graph[i][j] > graph[i][k] + graph[k][j]) graph[i][j] = graph[i][k] + graph[k][j];
        }
    }
}

console.log(graph);