const graph = [[], [2,3], [1,7], [1,4,5], [3,5], [3,4], [7], [2,6]];

let visited = Array.from({length : graph.length}, () => false);

function bfs(graph, start, visited) {
    const queue = [];

    queue.push(start);
    visited[start] = true;

    while(queue.length!==0)
    {
        const now = queue.shift();
        process.stdout.write(`${now} `);

        for(const adj of graph[now]){
            if(!visited[adj]){
                queue.push(adj);
                visited[adj] = true;
            }
        }
    }
}

function dfs(graph, start, visited){
    const stack = [];
    stack.push(start);
    while(stack.length!==0){
        const now = stack.pop();

        if(visited[now]) continue;
        else visited[now] = true;
        process.stdout.write(`${now} `);

        for(let i=graph[now].length-1; i>=0; i--)
        {
            const adj = graph[now][i];
            if(!visited[adj]) {
                stack.push(adj);
            }
        }
    }
}

bfs(graph, 1, visited);
process.stdout.write('\n');
visited = visited.map(() => false);
dfs(graph, 1, visited);
process.stdout.write('\n');