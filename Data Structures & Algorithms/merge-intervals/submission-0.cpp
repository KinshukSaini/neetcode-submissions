class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        vector<vector<int>> res;
        for(int i = 0; i < n; i++){
            int m = res.size();
            if(m == 0) res.push_back(intervals[i]);
            else if(intervals[i][0] <= res[m - 1][1]){
                res[m - 1][1] = max(res[m-1][1], intervals[i][1]);
            }
            else res.push_back(intervals[i]);
            
        }

        return res;
    }
};
