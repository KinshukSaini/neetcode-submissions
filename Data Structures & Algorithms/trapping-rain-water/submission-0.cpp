class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> pref(n, 0);
        int num = 0;
        for(int i = 0; i < n; i++){
            pref[i] = num;
            num = max(num, height[i]);
        }
        vector<int> suf(n, 0);
        num = 0;
        for(int i = n - 1; i >= 0; i--){
            suf[i] = num;
            num = max(num, height[i]);
        }
        
        int maxArea = 0;
        for(int i = 0; i < n; i++){
            int area = min(pref[i], suf[i]) - height[i];
            if(area > 0) maxArea += area;
        }
        return maxArea;
    }
};
