class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int low = 0, high = 0;
        int res = 0;
        for(int i = 0; i < n; i++){
            int profit = prices[i] - prices[low];
            res = max(res, profit);
            if(prices[i] < prices[low]) low = i;
        }
        return res;
    }
};
