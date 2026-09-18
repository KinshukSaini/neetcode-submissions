class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();

        priority_queue<pair<int, int>> pq;
        vector<int> res;
        for(int i = 0; i < k; i++) pq.push({nums[i], i});
        for(int i = k - 1; i < n; i++){
            while(!pq.empty() && pq.top().second < i - k + 1) pq.pop();
            pq.push({nums[i], i});
            res.push_back(pq.top().first);
        }
        return res;
    }
};
