class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0;
        map<char, int> mpp;
        int left = 0, right = 0;
        int n = s.size();
        while(left < n && right < n){
            if(mpp[s[right]]){
                mpp[s[left]]--;
                left++;
            }
            else{
                mpp[s[right]]++;
                res = max(res, right - left + 1);
                right++;
            }
        }
        return res;
    }
};
