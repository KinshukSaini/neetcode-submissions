class Solution {
public: 
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        queue<pair<int,pair<int, int>>> q;
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(grid[i][j] == 0) q.push({0, {i, j}});
            }
        }
        vector<int> dx = {0, 0, -1, 1};
        vector<int> dy = {-1, 1, 0, 0};
        while(!q.empty()){
            auto p = q.front();
            int x = p.second.first;
            int y = p.second.second;
            int level = p.first;
            q.pop();
            for(int k = 0; k < 4; k++){
                int X = x + dx[k];
                int Y = y + dy[k];
                if(X >= 0 && Y >= 0 && X < row && Y < col){
                    if(grid[X][Y] != -1 && grid[X][Y] != 0 && grid[X][Y] >= level + 1){
                        grid[X][Y] = level + 1;
                        q.push({level + 1, {X, Y}});
                    }
                }
            }
        }
    }
};