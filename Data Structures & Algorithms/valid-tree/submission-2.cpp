class Solution {
public:
    bool dfs(int node, int parent, vector<vector<int>>& adj, vector<int>& vis) {
        vis[node] = 1;

        for (int n : adj[node]) {
            if (n == parent) continue;
            if (vis[n]) return false;
            if (!dfs(n, node, adj, vis)) return false;
        }

        return true;
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1) return false;

        vector<vector<int>> adj(n);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<int> vis(n, 0);

        if (!dfs(0, -1, adj, vis)) return false;

        for (int num : vis) {
            if (num == 0) return false;
        }

        return true;
    }
};