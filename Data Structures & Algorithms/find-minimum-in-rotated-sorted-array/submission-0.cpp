class Solution {
public:
    int findMin(vector<int> &nums) {
        int n = nums.size();
        int left = 0, right = n - 1;
        int res = nums[0];
        while(left < right){
            if(nums[left] < nums[right]){
                res = min(res, nums[left]);
                break;
            }
            int mid = left + (right - left) / 2;
            res = min(res, nums[left]);
            res = min(res, nums[mid]);
            res = min(res, nums[right]);
            if(nums[mid] >= nums[left]){
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }
        return res;
    }
};
