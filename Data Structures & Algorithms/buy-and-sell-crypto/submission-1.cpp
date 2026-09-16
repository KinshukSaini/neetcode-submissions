class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int n = prices.size();
        int low = 0, high = 1;
        for(int i = 1; i < n; i++){
            maxProfit = max(maxProfit, prices[high] - prices[low]);
            if(prices[i] < prices[low]){
                low = i;
            }
            high++;
        }
        return maxProfit;
    }
};
