class Solution {
public:
    int func(vector<int>& nums, vector<int>& dp, int i, int n){
        if(i >= n) return 0;
        if(dp[i] != -1) return dp[i];
        int a = nums[i] + func(nums, dp, i + 2, n);
        int b = func(nums, dp, i + 1, n);

        return dp[i] = max(a, b);
    }
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        if(n == 1) return nums[0];
        vector<int> dp1(n, -1);
        int res1 = func(nums, dp1, 0, n - 1);
        vector<int> dp2(n, -1);
        int res2 = func(nums, dp2, 1, n);
        return max(res1, res2);
    }
};
