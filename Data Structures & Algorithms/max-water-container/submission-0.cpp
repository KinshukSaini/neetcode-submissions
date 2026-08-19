class Solution {
public:
    int maxArea(vector<int>& heights) {
        int res = INT_MIN;
        int n = heights.size();
        int i = 0, j = n - 1;
        while(i < j){
            int area = (j - i) * min(heights[i], heights[j]);
            res = max(res, area);

            if(heights[j] < heights[i]) j--;
            else i++;
        }
        return res;
    }
};
