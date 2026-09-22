class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int maxArea = 0;
        stack<pair<int, int>> st;
        
        for(int i = 0; i < n; i++){
            int start = i;
            while(!st.empty() && heights[i] < st.top().second){
                int area = st.top().second * (i - st.top().first);
                maxArea = max(area, maxArea);
                start = st.top().first;
                st.pop();
            }
            st.push({start, heights[i]});
        }
        while(!st.empty()){
            int area = st.top().second * (n - st.top().first);
            maxArea = max(area, maxArea);
            st.pop();
        }
        return maxArea;
    }
};
