class Solution {
public:
    int solve(vector<int>& nums, int i, vector<int>& dp){
        if(i < 0) return 0;
        if(dp[i] != -1) return dp[i];
        int a = 0, b = 0;
        a = nums[i] + solve(nums, i - 2, dp);
        b = solve(nums, i - 1, dp);
        return dp[i] = max(a, b);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return solve(nums, n - 1, dp);
    }
};
