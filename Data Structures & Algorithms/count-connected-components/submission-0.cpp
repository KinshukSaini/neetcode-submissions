class Solution {
public:
    void traverse(int node, vector<vector<int>> adj, vector<int>& vis){
        vis[node] = 1;
        for(int n : adj[node]){
            if(vis[n]) continue;
            vis[n] = 1;
            traverse(n, adj, vis);
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        int res = 0;
        vector<vector<int>> adj(n);


        for(const auto& edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<int> vis(n, 0);
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                traverse(i, adj, vis);
                res++;
            }
        }
        return res;
    }
};
