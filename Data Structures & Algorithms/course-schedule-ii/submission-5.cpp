class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> inDegree(numCourses);
        for(int i = 0; i < prerequisites.size(); i++){
            inDegree[prerequisites[i][0]]++;
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        vector<int> res;
        queue<int> q;
        for(int i = 0; i < numCourses; i++){
            if(inDegree[i] == 0) q.push(i);
        }

        while(!q.empty()){
            int n = q.front();
            q.pop();

            if(inDegree[n] == 0){
                res.push_back(n);
            }

            for(int node : adj[n]){
                if(inDegree[node] != 0){
                    inDegree[node]--;
                    if(inDegree[node] == 0) q.push(node);
                }
            }
        }
        if(res.size() == numCourses) return res;
        return {};
    }
};
