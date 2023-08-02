import java.util.*;
class Solution {
    // 방문 여부
    boolean [] isVisited;
    List <String> allRoutes;
    
    public String[] solution(String[][] tickets) {
        isVisited = new boolean [tickets.length];
        allRoutes = new ArrayList<>();
        
        dfs("ICN", "ICN", 0, tickets);
        
        Collections.sort(allRoutes);
        String[] answer = allRoutes.get(0).split(" ");
        
        return answer;
    }
    
    public void dfs(String start, String route, int cnt, String[][] tickets)
    {
        if(cnt==tickets.length)
        {
            allRoutes.add(route);
            return;
        }
        for(int i=0; i<tickets.length; i++)
        {
            if(isVisited[i]) continue;
            if(start.equals(tickets[i][0])) {
                isVisited[i] = true;
                dfs(tickets[i][1], route + " " + tickets[i][1], cnt+1, tickets);
                isVisited[i] = false;
            }
        }
    }
}