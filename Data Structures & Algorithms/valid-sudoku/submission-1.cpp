class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        for(int i = 0; i < 9; i++){
            map<char, int> mpp;
            for(int j = 0; j < 9; j++){
                if(board[i][j] == '.') continue;
                if(mpp[board[i][j]]) return false; 
                mpp[board[i][j]]++;
            }
        }
        for(int i = 0; i < 9; i++){
            map<char, int> mpp;
            for(int j = 0; j < 9; j++){
                if(board[j][i] == '.') continue;
                if(mpp[board[j][i]]) return false; 
                mpp[board[j][i]]++;
            }
        }
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                map<char, int> mpp;
                for(int x = i * 3; x < (i * 3) + 3; x++){
                    for(int y = j * 3; y < (j * 3) + 3; y++){
                        if(board[x][y] == '.') continue;
                        if(mpp[board[x][y]]) return false;
                        mpp[board[x][y]]++;
                    }
                }
            }
        }
        return true;
    }
};
