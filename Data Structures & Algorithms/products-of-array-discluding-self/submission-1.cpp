class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int prd = 1, cnt0 = 0;
        for(int num : nums){
            if(num != 0) prd *= num;
            else cnt0++;
        } 
        vector<int> res(n, 0);
        if(cnt0 > 1) return res;
        if(cnt0 == 1){
            for(int i = 0; i < n; i++){
                if(nums[i] == 0) res[i] = prd;
            }
            return res;
        }
        for(int i = 0; i < n; i++){
            res[i] = prd / nums[i];
        }
        return res;
    }
};
