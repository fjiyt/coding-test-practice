import java.util.*;
import java.io.*;

class Solution {
    public class Range {
        int s, e;
        Range(int s, int e)
        {
            this.s = s;
            this.e = e;
        }
    }
    public int solution(int[][] targets) {
        int answer = 0;
        ArrayList <Range> list = new ArrayList <> ();
        Arrays.sort(targets, new Comparator<int[]>() {
            @Override
            public int compare(int [] o1, int [] o2)
            {
                if(o1[0] == o2[0]) return o1[1] - o2[1];
                return o1[0]-o2[0];
            }
        });
        
        for(int i=0; i<targets.length; i++)
        {
            int s = targets[i][0];
            int e = targets[i][1];
            boolean isNew = true;
            
            for(Range r : list) {
                // list 값 갱신 -> 사이에 존재
                if(s >= r.s && s < r.e)
                {
                    if(e <= r.e)
                    {
                        r.s = s;
                        r.e = e;
                    }
                    else {
                        r.s = s;
                    }
                    isNew = false;
                }
                else if (s<r.s)
                {
                    if(e < r.e && e > r.s)
                    {
                        r.e = e;
                        isNew = false;
                    }
                    else if(e >= r.e) {
                        isNew = false;
                    }
                }
                if(!isNew) break;
            }
            
            if(isNew) {
                list.add(new Range(s,e));
            }
        }
        
        answer = list.size();
        return answer;
    }
}