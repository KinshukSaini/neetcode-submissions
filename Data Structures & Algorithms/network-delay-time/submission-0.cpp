class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for(auto time : times){
            adj[time[0] - 1].push_back({time[1] - 1, time[2]});
        }
        vector<int> duration(n, INT_MAX);
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        duration[k - 1] = 0;
        pq.push({0, k - 1});
        while(!pq.empty()){
            auto pr = pq.top();
            int d = pr.first;
            int node = pr.second;
            pq.pop();
            for(auto p : adj[node]){
                int t = d + p.second;
                if(t < duration[p.first]){
                    duration[p.first] = t;
                    pq.push({t, p.first});
                }
            }
        }

        int res = 0;
        for(int t : duration){
            if(t == INT_MAX) return -1;
            res = max(res, t);
        }
        return res;
    }
};
