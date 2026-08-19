class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen = 0;
        int n = s.size();
        int i = 0, j = 0;
        map<char, pair<int, int>> mpp;
        while(j < n){
            if(mpp[s[j]].first == 1){
                while(i <= mpp[s[j]].second){
                    mpp[s[i]].first--;
                    i++;
                }
            }
            maxLen = max(maxLen, j - i + 1);
            mpp[s[j]].first++;
            mpp[s[j]].second = j;
            j++;
        }
        return maxLen;
    }
};
