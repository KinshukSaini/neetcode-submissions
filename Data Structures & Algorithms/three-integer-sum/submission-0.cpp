class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        set<vector<int>> res;
        for(int i = 0; i < n - 2; i++){
            int j = i + 1;
            int k = n - 1;
            while(j < k){
                int sum = nums[i] + nums[j] + nums[k];
                if(sum == 0){
                    if(res.find({nums[i], nums[j], nums[k]}) == res.end()) res.insert({nums[i], nums[j], nums[k]});
                    j++;
                }
                else if(sum < 0) j++;
                else{
                    k--;
                }
            }
        }
        vector<vector<int>> ans(res.begin(), res.end());
        return ans;
    }
};
