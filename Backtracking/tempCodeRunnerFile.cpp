
        if(!isVisited[i])
        {
            isVisited[i] = true;
            arr[cnt] = sortingNum[i];
            dfs(cnt+1);
            isVisited[i] = false;
        }
    }