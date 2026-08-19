class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int, int>> st;
        int maxArea = 0;
        int n = heights.size();
        for(int i = 0; i <= n; i++){
            int start = i;
            int height = (i == n) ? 0 : heights[i];
            while(!st.empty() && height < st.top().second){
                int idx = st.top().first;
                int h = st.top().second;
                int area =  h * (i - idx);
                st.pop();
                maxArea = max(maxArea, area); 
                start = idx;
            }
            st.push({start, height});
        }
        return maxArea;
    }
};
