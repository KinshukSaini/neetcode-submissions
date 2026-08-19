class Solution {
public:

    int traversal(int i, int j, vector<vector<int>>& grid, vector<vector<bool>>& vis){
        int n = grid.size(), m = grid[0].size();
        queue<pair<int, int>> q;
        q.push({i, j});
        int area = 0;
        vector<int> dx = {-1, +1, 0, 0};
        vector<int> dy = {0, 0, -1, +1};
        while(!q.empty()){
            area++;
            auto p = q.front();
            int x = p.first;
            int y = p.second;
            q.pop();

            for(int k = 0; k < 4; k++){
                int X = x + dx[k];
                int Y = y + dy[k];
                if(X >= 0 && Y >= 0 && X < n && Y < m && grid[X][Y] && !vis[X][Y] ){
                    vis[X][Y] = 1;
                    q.push({X, Y});
                }
            }
        }
        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> vis(m, vector<bool> (n, 0));
        int maxArea = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(!vis[i][j] && grid[i][j]){
                    vis[i][j] = 1;
                    maxArea = max(maxArea, traversal(i, j, grid, vis));
                }
            }
        }
        return maxArea;
    }
};
