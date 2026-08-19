class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        // C3 B4.5 A10 D3
        // C3 D3 B4.5 A10
        // A10 B4.5 C3 D3

        // A5 B2.6 C6
        int n = position.size();
        vector<pair<int, int>> cars;
        for(int i = 0; i < n; i++) cars.push_back({position[i], speed[i]});

        sort(cars.rbegin(), cars.rend());
        int count = 0;
        stack<double> st;
        for(auto car : cars){
            int p = car.first;
            int s = car.second;
            double t = ((double)target - (double)p) / (double) s;
            if(st.empty()){
                st.push(t);
            }
            else{
                if(t > st.top()){
                    st.push(t);
                }
            }
        }
        
        return st.size();
    }
};
