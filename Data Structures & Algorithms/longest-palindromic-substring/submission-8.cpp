#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int maxLen = 1;
    int start = 0;

    bool isPal(string& s, int i, int j, vector<vector<int>>& dp) {
        if (i >= j) return true;
        if (dp[i][j] != -1) return dp[i][j];

        // 1. Determine if s[i..j] is a palindrome
        bool curr = (s[i] == s[j]) && isPal(s, i + 1, j - 1, dp);

        if (curr && (j - i + 1 > maxLen)) {
            maxLen = j - i + 1;
            start = i;
        }

        // 2. Explore other substring intervals
        isPal(s, i + 1, j, dp);
        isPal(s, i, j - 1, dp);


        return dp[i][j] = curr;
    }

    string longestPalindrome(string s) {
        int n = s.size();
        if (n <= 1) return s;

        maxLen = 1;
        start = 0;
        vector<vector<int>> dp(n, vector<int>(n, -1));

        isPal(s, 0, n - 1, dp);

        return s.substr(start, maxLen);
    }
};