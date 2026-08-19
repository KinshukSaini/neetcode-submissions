class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> mpp;

        for(int num : nums){
            mpp[num]++;
        }
        
        vector<pair<int, int>> vec(mpp.begin(), mpp.end());

        sort(vec.begin(), vec.end(), [](auto& a, auto& b){
            return a.second > b.second;
        });
        vector<int> res;
        for(auto [n, f] : vec){
            if(res.size() >= k) break;
            res.push_back(n);
        }
        return res;
    }
};
