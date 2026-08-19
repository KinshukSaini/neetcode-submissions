class Solution {
public:
    int solve(string& t1, string& t2, int i, int j, vector<vector<int>>& dp){
        if(i < 0 || j < 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int same = 0;
        if(t1[i] == t2[j]) same = 1 + solve(t1, t2, i - 1, j - 1, dp);
        int first = solve(t1, t2, i - 1, j, dp);
        int second = solve(t1, t2, i, j - 1, dp);
        return dp[i][j] = max(same, max(first, second));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        vector<vector<int>> dp(n, vector<int> (m, -1));
        return solve(text1, text2, n - 1, m - 1, dp);
    }
};
