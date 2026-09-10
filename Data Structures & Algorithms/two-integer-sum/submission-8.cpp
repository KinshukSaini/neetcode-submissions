class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, pair<bool, int>> mpp;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            int req = target - nums[i];
            if(mpp[req].first) return {mpp[req].second, i};
            mpp[nums[i]] = {true, i};
        }
        return {-1, -1}; 
    }
};
