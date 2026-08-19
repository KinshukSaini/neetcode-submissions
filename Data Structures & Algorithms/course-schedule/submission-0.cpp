class Solution {
public:
    bool isCycle(int& i, vector<vector<int>>& adj, vector<int>& vis){
        vis[i] = 1;
        for(int num : adj[i]){
            if(vis[num] == 1) return true;
            if(isCycle(num, adj, vis)) return true;
        }
        vis[i] = 2;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses, vector<int> (0, 0));
        for(vector<int> arr : prerequisites){
            adj[arr[1]].push_back(arr[0]);
        }

        vector<int> vis(numCourses, 0);

        for(int i = 0; i < numCourses; i++){
            if(!vis[i] && isCycle(i, adj, vis)) return false;
        }

        return true;
    }
};
