// 크루스칼 알고리즘 (MST)
import java.util.*;

class Solution {
    ArrayList <Node> list;
    int [] parent;
    private int n;
    
    public int solution(int n, int[][] costs) {
        int answer = 0;
        this.n = n;
        parent = new int [n];
        list = new ArrayList <> ();
        for(int i=0; i<costs.length; i++)
        {
            int x = costs[i][0];
            int y = costs[i][1];
            int c = costs[i][2];
            
            list.add(new Node(x,y,c));
            list.add(new Node(y,x,c));
        }
        
        
        return kruskal();
    }
    public int kruskal()
    {
        Collections.sort(list, (a,b) -> Integer.compare(a.c, b.c));
        
        for(int i=0; i<n; i++)
        {
            parent[i] = i;
        }
        
        int cnt = 0;
        int weight = 0;
        for(int i=0; i<list.size(); i++)
        {
            if(cnt==n-1) break;
            Node n = list.get(i);
            
            if(union(n.x, n.y))
            {
                cnt++;
                weight += n.c;
            }
        }
        
        return weight;
    }
    
    public boolean union(int x, int y)
    {
        x = find(x);
        y = find(y);
        
        if(x==y) return false;
        
        if(x<y) parent[y] = x;
        else parent[x] = y;
        
        return true;
    }
    
    public int find(int x)
    {
        if(parent[x] == x) return x;
        return find(parent[x]);
    }
}

class Node{
    int x;
    int y;
    int c;
    
    Node(int x,int y, int c)
    {
        this.x = x;
        this.y = y;
        this.c = c;
    }
}