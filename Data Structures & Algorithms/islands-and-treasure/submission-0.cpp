class Solution {
public: 
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int row = grid.size();
        if (row == 0) return;
        int col = grid[0].size();
        
        queue<pair<int, int>> q;

        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(grid[i][j] == 0) q.push({i, j});
            }
        }

        int dx[] = {0, 0, -1, 1};
        int dy[] = {-1, 1, 0, 0};

        while(!q.empty()){
            auto [x, y] = q.front();
            q.pop();

            for(int i = 0; i < 4; i++){
                int nx = x + dx[i], ny = y + dy[i];
                if(nx >= 0 && nx < row && ny >= 0 && ny < col && grid[nx][ny] == 2147483647){
                    grid[nx][ny] = grid[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
    }
};