class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int n = nums.size();
        int maxLen = 1;
        map<int, bool> mpp;
        vector<int> arr;
        for(int num : nums) mpp[num] = 1; 
        for(auto [num, f] : mpp) arr.push_back(num);
        sort(arr.begin(), arr.end());
        int len = 1;
        for(int i = 1; i < arr.size(); i++){
            if(arr[i] - arr[i - 1] == 1) len++;
            else len = 1;
            maxLen = max(maxLen, len);
        }
        return maxLen;
    }
};
