class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<int> inDeg(n, 0);
        vector<vector<int>> adj(n);
        for(auto requisite : prerequisites){
            adj[requisite[1]].push_back(requisite[0]);
            inDeg[requisite[0]]++;
        }
        queue<int> q;
        for(int i = 0; i < n; i++){
            if(inDeg[i] == 0) q.push(i);
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(int child : adj[node]){
                inDeg[child]--;
                if(inDeg[child] == 0) q.push(child);
            }
        }

        for(int deg : inDeg) if(deg != 0) return false;
        return true;
    }
};
