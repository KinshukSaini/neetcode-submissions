class Solution {
public:
// 7:1.4 8:1.5 11:0.6 12:0.4 16:0.1
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        stack<int> st;
        vector<pair<int, int>> arr;
        int n = position.size();
        for(int i = 0; i < n; i++){
            arr.push_back({position[i], speed[i]});
        }
        sort(arr.begin(), arr.end());
        for(int i = n - 1; i >= 0; i--){
            if(st.empty()){
                st.push(i);
            }
            else{
                float leadTime = ((float)target - (float)arr[st.top()].first) / (float)arr[st.top()].second;
                float t = ((float)target - (float)arr[i].first) / (float)arr[i].second;
                if(t > leadTime) st.push(i);
            }            
        }
        return st.size();
    }
};
