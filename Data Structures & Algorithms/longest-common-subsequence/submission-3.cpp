class Solution {
public:
    int solve(string& t1, string& t2, int i, int j, vector<vector<int>>& dp){
        if(i == 0 || j == 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int same = 0;
        if(t1[i - 1] == t2[j - 1]) same = 1 + solve(t1, t2, i - 1, j - 1, dp);
        int first = solve(t1, t2, i - 1, j, dp);
        int second = solve(t1, t2, i, j - 1, dp);
        return dp[i][j] = max(same, max(first, second));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        vector<vector<int>> dp(n + 1, vector<int> (m + 1, 0));
        // return solve(text1, text2, n, m, dp);
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                int same = 0;
                if(text1[i - 1] == text2[j - 1]) same = 1 + dp[i - 1][j - 1];
                int first = dp[i - 1][j];
                int second = dp[i][j - 1];
                dp[i][j] = max(same, max(first, second));
            }
        }
        return dp[n][m];
    }
};
