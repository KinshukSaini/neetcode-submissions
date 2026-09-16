class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int l = 0, r = 0;
        int maxLen = 0;
        unordered_map<char, int> mpp;
        while(r < n){
            mpp[s[r]]++;
            int topChar = 0;
            for(auto [c, f] : mpp){
                topChar = max(f, topChar);
            }
            while((r - l + 1) - topChar > k){
                topChar = 0;
                for(auto [c, f] : mpp){
                    topChar = max(f, topChar);
                }
                mpp[s[l]]--;
                l++;
            }
            maxLen = max(maxLen, r - l + 1);
            r++;
        }
        return maxLen;
    }
};
