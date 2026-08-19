class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> pre;
        vector<int> suf(nums.size());
        int p = 1;
        for(int i = 0; i < nums.size(); i++){
            p *= nums[i];
            pre.push_back(p);
        }
        p = 1;
        for(int i = nums.size() - 1; i >= 0; i--){
            p *= nums[i];
            suf[i] = p;
        }

        vector<int> res(nums.size());

        for(int i = 0; i < nums.size(); i++){
            if(i == 0){
                res[i] = suf[i + 1];
            }
            else if(i == nums.size() - 1){
                res[i] = pre[i - 1];
            }
            else{
                res[i] = pre[i - 1] * suf[i + 1];
            }
        }
        
        return res;
    }
};
