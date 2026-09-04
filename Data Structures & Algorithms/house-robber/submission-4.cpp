class Solution {
public:
    int solve(vector<int>& nums, int i, bool taken, vector<vector<int>>& dp){
        if(i == nums.size()) return 0;
        if(dp[i][taken] != -1) return dp[i][taken];
        int a = 0, b = 0;
        if(!taken) a = nums[i] + solve(nums, i + 1, true, dp);
        b = solve(nums, i + 1, false, dp);
        return dp[i][taken] = max(a, b);
    }
    int rob(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(), (vector<int> (2, -1)));
        return solve(nums, 0, false, dp);
    }
};
