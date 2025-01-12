class Solution {
    public int maxProfit(int[] prices) {
        int maxProfit = 0;
        int i = 0;
        int j = 1;
        while ( j < prices.length) {
            int currProfit = prices[j] - prices[i];
            if (maxProfit < currProfit) {
                maxProfit = currProfit;
            } else if (prices[j] < prices[i]) {
                i = j;
                j++;
            } else {
                j++;
            }
        }
        return maxProfit;
    }
}