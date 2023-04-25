class Solution {
    public int[] solution(int[] lottos, int[] win_nums) {
        int [] prize = {6,5,4,3,2,1};

        int[] answer = {0,0};
        
        int zeros = 0;
        int cnt = 0;
        for(int i=0; i<6; i++)
        {
            if(lottos[i]==0) { zeros++; continue; }
            for(int j=0; j<6; j++)
            {
                if(lottos[i] == win_nums[j]) cnt++;
            }
            
        }
        for(int i=0; i<6; i++)
        {
            if(cnt+zeros <= 1) { answer[0] = 6; break; }
            if(cnt+zeros == prize[i]) {
                answer[0] = i+1;
                break;
            }
        }
        for(int i=0; i<6; i++)
        {
            if(cnt <= 1) { answer[1] = 6; break; }
            if(cnt == prize[i]) {
                answer[1] = i+1;
                break;
            }
        }
        
        return answer;
    }
}