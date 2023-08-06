class Solution {
    public int[] solution(int brown, int yellow) {
        int[] answer = {0,0};
        for(int c = yellow; c>=1; c--)
        {
            if(yellow%c!=0) continue;
            int r = yellow / c;
            int total = (c+1) * 2 + (r+1) * 2;
            if((total == brown) && (c>=r)) {
                answer[0]=c+2;
                answer[1]=r+2;
            }
        }
        return answer;
    }
}