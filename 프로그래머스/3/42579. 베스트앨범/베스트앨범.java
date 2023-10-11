import java.util.*;

class Solution {
    public ArrayList solution(String[] genres, int[] plays) {
        ArrayList <Integer> answer = new ArrayList <> ();
        HashMap <String, Integer> hm = new HashMap <> ();
        
        for(int i=0; i<genres.length; i++)
        {
            if(hm.containsKey(genres[i]))
            {
                hm.put(genres[i], hm.get(genres[i]) + plays[i]);
            }
            else hm.put(genres[i], plays[i]);
        }
        
        PriorityQueue <Node> pq = new PriorityQueue <> (Node::compareTo);
        for(Map.Entry e : hm.entrySet())
        {
            pq.add(new Node((Integer)e.getValue(), (String)e.getKey()));
        }
        
        while(!pq.isEmpty())
        {
            Node n = pq.poll();
            // 같은 장르별 재생순위 순으로 정렬
            PriorityQueue <Song> sq = new PriorityQueue <> (Song::compareTo);
            for(int i=0; i<genres.length; i++)
            {
                if(genres[i].equals(n.genre))
                {
                    sq.add(new Song(i, plays[i]));
                }
            }
            
            // 많이 재생된 곡 두개 고르기
            int cnt = 0;
            while(!sq.isEmpty() && cnt < 2)
            {
                Song s = sq.poll();
                answer.add(s.id);
                cnt++;
            }
        }
        return answer;
    }
}

class Node {
    int cnt;
    String genre;
    
    Node(int cnt, String genre) {
        this.cnt = cnt;
        this.genre = genre;
    }
    
    public int compareTo(Node n)
    {
        return n.cnt - this.cnt;
    }
}

class Song{
    int id;
    int plays;
    
    Song(int id, int plays)
    {
        this.id = id;
        this.plays = plays;
    }
    
    public int compareTo(Song s)
    {
        if(this.plays==s.plays) return this.id - s.id;
        return s.plays - this.plays;
    }
}