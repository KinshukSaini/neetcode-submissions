class Solution {
public:
    void traversal(int i, int j, vector<vector<char>>& grid, vector<vector<bool>>& vis){
        queue<pair<int, int>> q;
        q.push({i, j});
        int n = grid.size(), m = grid[0].size();
        vector<int> dx = {-1, +1, 0, 0};
        vector<int> dy = {0, 0, -1, +1};
        while(!q.empty()){
            auto p = q.front();
            int x = p.first;
            int y = p.second;
            q.pop();
            for(int k = 0; k < 4; k++){
                int X = x + dx[k];
                int Y = y + dy[k];

                if(X >= 0 && Y >= 0 && X < n && Y < m && grid[X][Y] == '1' && !vis[X][Y]){
                    q.push({X, Y});
                    vis[X][Y] = 1;
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int cnt = 0;
        int n = grid.size(), m = grid[0].size();

        vector<vector<bool>> vis(n, vector<bool> (m, 0));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == '1' && !vis[i][j]){
                    cnt++;
                    traversal(i, j, grid, vis);
                }
            }
        }
        return cnt;
    }
};
