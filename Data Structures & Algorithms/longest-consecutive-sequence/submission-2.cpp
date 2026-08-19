class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() < 1) return nums.size();
        sort(nums.begin(), nums.end());
        int maxLen = 1;
        int len = 1;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] == nums[i - 1]) continue;
            if(nums[i] - 1 == nums[i - 1]){
                len++;
            }
            else{
                len = 1;
            }
            maxLen = max(len, maxLen);
        }
        return maxLen;
    }
};
