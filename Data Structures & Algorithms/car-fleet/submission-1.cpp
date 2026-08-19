class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> arr;
        for(int i = 0; i < speed.size(); i++){
            arr.push_back({position[i], speed[i]});
        }
        sort(arr.rbegin(), arr.rend());
        stack<float> st;
        for(int i = 0; i < arr.size(); i++){
            float hours = (float)(target - arr[i].first) / arr[i].second;
            if(st.empty()){
                st.push(hours);
            }
            else if(hours > st.top()){
                st.push(hours);
            }
        }
        return st.size();
    }
};
