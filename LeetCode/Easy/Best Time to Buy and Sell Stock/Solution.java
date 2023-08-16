class Solution {
    public int maxProfit(int[] prices) {
        int min = Integer.MAX_VALUE;
        int gain = 0;
        for(int i=0; i<prices.length; i++)
        { 
            if(min > prices[i]) min=prices[i];
            if(gain < prices[i] - min) {
                gain = prices[i] - min;
            }
        }

        return gain;
    }
}
