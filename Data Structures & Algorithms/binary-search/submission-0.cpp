class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int i = 0, j = n - 1;
        int m = 0;
        while(i < j){
            m = (i + j) / 2;
            if(nums[m] == target) return m;
            if(nums[m] < target) i = m + 1;
            if(nums[m] > target) j = m - 1;
        }
        if(nums[j] == target) return j;
        return -1; 
    }
};
