class Solution {
public:
    int func(vector<int>& nums, vector<int>& dp, int i){
        if(i >= nums.size()) return 0;
        if(dp[i] != -1) return dp[i];
        int a = nums[i] + func(nums, dp, i + 2);
        int b = func(nums, dp, i + 1);

        return dp[i] = max(a, b);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        int res = func(nums, dp, 0);
        return res;
    }
};
